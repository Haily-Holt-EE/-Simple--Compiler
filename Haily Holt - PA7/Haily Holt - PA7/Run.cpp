#include "stdafx.h"
#include "Fix.h"

/*What function does: Converts the initial input from the user (in a character array) to a list, which allows for number more than one
digit to be dealt with, as well as negative numbers. This is done by going through the character array and using 
a switch statement to differentiate between numbers and specific characters, allowing nodes to be created for each
individual item, including numbers that are more than one digit. 
Inputs: The input equation from the user, which is stored in a character array. 
Outputs: A new list that contains the items of the infix equation.
*/
void Run::parse( string inp )
{
	int index = 0, temp = 0, neg = 1;
	FixItem *curr = NULL;


	for (index = 0; index < inp.size(); index++)
	{
		switch (inp[index])
		{
		case '(': 
			infix->insertAtEnd(infix->top->makeNode(LEFTP, '('));
			break;
		case ')':
			infix->insertAtEnd(infix->top->makeNode(RIGHTP, ')'));
			break;
		default:
			if ((inp[index] == '+') || (inp[index] == '-') || (inp[index] == '*') || (inp[index] == '/') || (inp[index] == '^') || (inp[index] == '%'))
			{
				if (inp[index] == '-')//Checks to see if this indicates subtraction, or a negative number.
				{

					curr = infix->top;

					while (curr->next != NULL)
					{
						curr = curr->next;
					}
					if ((curr->type == OPER) || (curr->type == LEFTP))
					{
						neg = neg * -1;
					}
					else
					{
						infix->insertAtEnd(infix->top->makeNode(OPER, inp[index]));
					}
				}
				else
				{
					infix->insertAtEnd(infix->top->makeNode(OPER, inp[index]));
				}
			}
			else if ((inp[index] >= '0') && (inp[index] <= '9'))
			{
				temp = atoi (&inp[index]) * neg;//Reads in multi-digit numbers

				infix->insertAtEnd(infix->top->makeNode(NUMBER, temp));

				temp *= neg;

				while (temp >= 10)//Loop to know how many digits the number is, so we can advance our index that many spaces.
				{
					index++;
					temp = temp / 10;
				}
				neg = 1;
			}
			else if (((inp[index] >= 'A') && (inp[index] <= 'z')) || ((inp[index] <= 'a') && (inp[index] >= 'z')))
			{
				infix->insertAtEnd(infix->top->makeNode(ALPHA, inp[index]));
			}

		}
	}
}

/*What function does: Compares an operator from the infix list to the operator at the top of the stack, deciding it one holds precedence
over the other.
Inputs: Character from the infix list and the character from the top of the stack.
Outputs: Either 1 (true) or 0 (false). 
*/
int Run::operPrecedence( char first, char second )
{
	switch(first)
	{
	case '*':
		return((second == '+') || (second == '-'));
		break;
	case '/':
		return((second == '+') || (second == '-'));
	case '%':
		return((second == '+') || (second == '-'));
		break;
	case '^':
		return((second == '+') || (second == '-') || (second == '*') || (second == '/'));
	default: return 0;
	}
}

/*What function does: Very similar to the operPrecedence function, only this one checks to see if one operator is of equal precedence
to another. 
Inputs: Inputs: Character from the infix list and the character from the top of the stack.
Outputs: Either 1 (true) or 0 (false). 
*/
int Run::operEqual( char first, char second )
{
	switch(first)
	{
	case '*':
		return((second == '*') || (second == '/') || (second == '%'));
		break;
	case '/':
		return((second == '*') || (second == '/') || (second == '%'));
		break;
	case '+':
		return((second == '+') || (second == '-'));
		break;
	case '-':
		return((second == '+') || (second == '-'));
		break;
	default: return 0;
	}
}

/*What function does: This function is very simple. It simply takes in the operator encountered in the postfixEval function, then takes
the two popped numbers from the stack and applied the operator to them.
Inputs: The operator encountered in the postfixEval function, and two FixItem pointers that were popped from the stack in the postfixEval
function and contain values that need to have the operator applied to.
Outputs: Returns the value of the operation applied to the numbers.
*/
int Run::evaluationSwitch( char oper )
{
	switch(oper)
	{
	case '+':
		return(ADD * 1000);
		break;
	case '-':
		return(SUBTRACT * 1000);
		break;
	case '*':
		return(MULTIPLY * 1000);
		break;
	case '/':
		return(DIVIDE * 1000);
		break;
	case '%':
		return(MOD * 1000);
		break;
	case '^':
		return(EXPO * 1000);
		break;
	default: return 0;
	}
}

/*What function does: This function solves the initial equation entered by the user by evaluating the postfix expression. It enters numbers
from the postfix expression into the stack until an operator is reached. If an operator is found, the top two numbers
of the stack are popped, then evaluated using the operator that was encountered. That answer is then pushed onto the
stack, and this is repeated until the end of the postfix expression has been reached. 
Inputs: The postfix list, and the overall stack of the program.
Outputs: A modified stack. The top of it contains the evaluated answer to the initial equation entered by the user.
*/
void Run::postfixEval(Compiler *forPostFix, int assignLocation)
{
	FixItem *current = NULL;
	FixItem *temp = new FixItem;
	FixItem *firstNum = new FixItem;
	FixItem *secondNum = new FixItem;
	int numValue = 0, locationItem = 0;
	int memLocLeft = 0, memLocRight = 0;
	int memCounter = 999;

	if (postfix->top != NULL)
	{
		current = postfix->top;

		while (current != NULL)
		{
			while(current->type != OPER)
			{

				if (current->type == NUMBER)
				{
					locationItem = forPostFix->FindSymbol(current->val, CONS);
				}
				else
				{
					locationItem = forPostFix->FindSymbol(current->val, VAR);
				}

				evaluatedAnswer->push(postfix->top->makeNode(ADDRES, locationItem));
				current = current->next;
			}

			if (current->type == OPER)
			{
				firstNum = evaluatedAnswer->pop();
				secondNum = evaluatedAnswer->pop();

				forPostFix->instructions.push_back((LOAD * 1000) + secondNum->val);
				forPostFix->instructionCounter++;

				temp = current;
				current = current->next;
				temp->next = NULL;
				numValue = evaluationSwitch(temp->val);
				numValue += firstNum->val;
				forPostFix->instructions.push_back(numValue);
				forPostFix->instructionCounter++;
				forPostFix->instructions.push_back((STORE * 1000) + memCounter);
				forPostFix->instructionCounter++;
				evaluatedAnswer->push(postfix->top->makeNode(ADDRES, memCounter));

				memCounter--;
			}
		}

		forPostFix->instructions.push_back((STORE * 1000) + assignLocation);
		forPostFix->instructionCounter++;
	}

}

/*What function does: Converts the infix expression to a postfix expression by creating a new list with the infix nodes arranged in such
a way that it creates the postfix expression. If a number is encountered in the infix list, the number is put into 
the postfix list. If an operator is encountered, it is either pushed to the stack or pushed after the rest of the 
operators in the stack have been popped, depending on how the operators compare. If the a right parenthesis is 
encountered, all of the operators are popped from the stack until a left parenthesis is found, then that is popped. 
All of this is done until the stack is empty.
Inputs: The infix list and the postfix list.
Outputs: A modified postfix list with each node arranged so it forms the postfix expression.
*/
void Run::toPostfix()
{
	Stack *s = new Stack();
	FixItem *current = NULL;
	FixItem *popData = NULL;
	int item = 0;

	if (infix->top != NULL)
	{
		infix->insertAtEnd(infix->top->makeNode(RIGHTP, ')'));
		current = infix->top;
		s->push(infix->top->makeNode(LEFTP, '('));

		while(s->getNode() != NULL)
		{
			if (current->type == NUMBER)
			{	
				FixItem *temp = new FixItem(current->getType(), current->getValue());
				current = current->next;
				postfix->insertAtEnd(temp);
			}
			else if (current->type == OPER)
			{

				if ((operPrecedence(s->peek()->val, current->val)) || (operEqual(s->peek()->val, current->val)))
				{
					while ((operPrecedence(s->peek()->val, current->val)) || (operEqual(s->peek()->val, current->val)))
					{
						popData = s->pop();					
						postfix->insertAtEnd(popData);
					}

					FixItem *temp = new FixItem(current->getType(), current->getValue());
					current = current->next;
					s->push(temp);
				}
				else
				{
					FixItem *temp = new FixItem(current->getType(), current->getValue());
					current = current->next;
					s->push(temp);
				}

			}
			else if (current->type == ALPHA)
			{
				FixItem *temp = new FixItem(current->getType(), current->getValue());
				current = current->next;
				postfix->insertAtEnd(temp);
			}
			else if (current->type == LEFTP)
			{
				FixItem *temp = new FixItem(current->getType(), current->getValue());
				current = current->next;
				s->push(temp);
			}
			else if (current->type == RIGHTP)
			{
				while (s->peek()->type != LEFTP)
				{
					popData = s->pop();
					postfix->insertAtEnd(popData);
				}
				current = current->next;
				s->pop();//Popping LEFTP
			}
		}
	}
}
/*What function does: Constructor for Run class.
Inputs: None.
Outputs: Initialized class.
*/
Run::Run()
{
	infix = new List();
	postfix = new List();
	evaluatedAnswer = new Stack();
}

/*What function does: Getter for Evaluated Answer stack
Inputs: None
Outputs: Stack pointer.
*/
Stack * Run::getEvaluatedAnswer()
{
	return evaluatedAnswer;
}
