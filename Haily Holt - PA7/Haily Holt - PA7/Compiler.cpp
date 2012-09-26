#include "stdafx.h"
#include "Compiler.h"

/*What function does: Populates a table (vector of Table classes) with characters seen in the written code.
Does this to prevent allocating memory multiple times for the same variable. Also
allows searching for line numbers when a flag is found (for branching). Lastly, this
function also creates a vector of the Simpletron instructions, based on what is read
in.
Inputs: None, besides the string that contains all of the program lines (which is then broken into individual
words for analyzing.
Outputs: A table with variables, constants, and line numbers, as well as a vector of instructions. Also returns
true or false to let the program know if the code was correct or not.
*/
bool Compiler::populateTable()
{
	bool success = false;
	int index = 0, index2 = 0, tableCounter = 0, memoryCounter = 0;
	string temp;
	vector<string> eachWord;
	string equation;
	int memoryAssignment;
	Compiler Post;
	Compiler Temp;

	Table.clear();
	instructions.clear();
	instructionCounter = 0;
	tableCounter = 0;
	flags.clear();
	information->~topLists();
	dividedInstructions.clear();
	equation = "";


	for(index2 = 0; index2 < programLines.size(); index2++)
	{
		equation = "";
		eachWord.clear();
		temp = "";

		this->infixPostfixEvaluations->infix->~List();
		this->infixPostfixEvaluations->postfix->~List();
		this->infixPostfixEvaluations->infix = NULL;
		this->infixPostfixEvaluations->postfix = NULL;
		this->infixPostfixEvaluations->infix = new List();
		this->infixPostfixEvaluations->postfix = new List();

		for (index = 0; index < programLines[index2].length(); index++)
		{
			if (programLines[index2][index] != ' ')
			{
				temp += programLines[index2][index];
			}
			else
			{
				eachWord.push_back(temp);
				temp.clear();
			}
		}

		eachWord.push_back(temp);

		for(index = 0; index < eachWord.size(); index++)
		{
			if ((index == 0) && (atoi(eachWord[index].c_str())))
			{
				TableEntry tempTable(atoi(eachWord[index].c_str()), LINE, instructionCounter);
				Table.push_back(tempTable);
				success = true;
			}
			else if ((index == 0) && (!atoi(eachWord[index].c_str())))
			{
				success = false;
				break;
			}
			else if ((index == 1) && (eachWord[index] == "rem"))
			{
				success = true;
				continue;
			}
			else if ((index == 1) && (eachWord[index] != "rem"))
			{
				if (eachWord[index] == "input")
				{
					if (eachWord.size() != 3)
					{
						success = false;
						break;
					}
					if(FindSymbol(eachWord[2][0], VAR) != -1)
					{
						instructions.push_back((READ * 1000) + FindSymbol(eachWord[2][0], VAR));
						//flags.push_back(-1);
						instructionCounter++;
						success = true;
					}
					else
					{
						TableEntry tempTable(eachWord[2][0], VAR, memoryCounter);
						Table.push_back(tempTable);
						success = true;
						instructions.push_back((READ * 1000) + memoryCounter);
						//flags.push_back(-1);
						instructionCounter++;
						memoryCounter++;
					}
				}
				else if (eachWord[index] == "let")
				{
					char Operator = '\0';
					int memLocRest = 0;
					int memLocAssignVar = 0; // for y
					//60 let y = 9 + x;

					if (eachWord.size() < 7)
					{
						success = false;
						break;
					}

					int tempType = VarOrConst(eachWord[2].c_str());
					Operator = eachWord[5][0];

					if (eachWord[3][0] != '=')
					{
						success = false;
						break;
					}
					if ((Operator != '+') && (Operator != '-') && (Operator != '/') && (Operator != '*') && (Operator != '%') && (Operator != '^'))
					{
						success = false;
						break;
					}

					if (tempType != EMPTYTYPE)
					{
						if (tempType == CONS)
						{
							memLocAssignVar = FindSymbol(atoi(eachWord[2].c_str()), tempType);
						}
						else
						{
							memLocAssignVar = FindSymbol(eachWord[2][0], tempType);
						}

						if (memLocAssignVar == -1)
						{
							TableEntry tempTable(0, tempType, memoryCounter);
							if (tempType == VAR)
							{
								tempTable.setSymbol(eachWord[2][0]);
							}
							else
							{
								tempTable.setSymbol(atoi(eachWord[2].c_str()));
							}

							Table.push_back(tempTable);
							success = true;
							memLocAssignVar = memoryCounter;
							memoryCounter++;
						}

						memoryAssignment = memLocAssignVar;
					}
					else
					{
						success = false;
						break;
					}

					for (int j = 4; j < eachWord.size(); j++)
					{
						tempType = VarOrConst(eachWord[j].c_str());

						if (j == 4)
						{
							equation = eachWord[j].c_str(); 
						}
						else
						{
							equation += eachWord[j].c_str();
						}

						equation += " ";


						if (tempType != EMPTYTYPE)
						{

							if (tempType == CONS)
							{
								memLocRest = FindSymbol(atoi(eachWord[j].c_str()), tempType);
							}
							else
							{
								memLocRest = FindSymbol(eachWord[j][0], tempType);
							}

							if (memLocRest == -1)
							{
								TableEntry tempTable(0, tempType, memoryCounter);

								if (tempType == VAR)
								{
									tempTable.setSymbol(eachWord[j][0]);
								}
								else
								{
									tempTable.setSymbol(atoi(eachWord[j].c_str()));
									information->InsertInList(memoryCounter, (atoi(eachWord[j].c_str())));
								}

								Table.push_back(tempTable);
								success = true;
								memLocRest = memoryCounter;
								memoryCounter++;
							}
						}
						
					}

					infixPostfixEvaluations->parse(equation);
					infixPostfixEvaluations->toPostfix();
					infixPostfixEvaluations->postfixEval(this, memoryAssignment);

				}
				else if (eachWord[index] == "print")
				{
					if (eachWord.size() != 3)
					{
						success = false;
						break;
					}

					if (FindSymbol(eachWord[2][0], VAR) != -1)
					{
						instructions.push_back((WRITE * 1000) + FindSymbol(eachWord[2][0], VAR));
						//flags.push_back(-1);
						instructionCounter++;
						success = true;
					}
					else
					{
						success = false;
						break;
					}
				}
				else if (eachWord[index] == "if")
				{
					int memLocLeft = 0, memLocRight = 0;

					if (eachWord.size() != 7)
					{
						success = false;
						break;
					}

					int tempType = VarOrConst(eachWord[2].c_str());

					if (tempType != EMPTYTYPE)
					{
						if (tempType == CONS)
						{
							memLocLeft = FindSymbol(atoi(eachWord[2].c_str()), tempType);
						}
						else
						{
							memLocLeft = FindSymbol(eachWord[2][0], tempType);
						}

						if (memLocLeft == -1)
						{
							TableEntry tempTable(0, tempType, memoryCounter);
							if (tempType == VAR)
							{
								tempTable.setSymbol(eachWord[2][0]);
							}
							else
							{
								tempTable.setSymbol(atoi(eachWord[2].c_str()));
								information->InsertInList(memoryCounter, (atoi(eachWord[2].c_str())));
							}
							Table.push_back(tempTable);
							success = true;
							memLocLeft = memoryCounter;
							memoryCounter++;
						}

					}
					else
					{
						success = false;
						break;
					}

					tempType = VarOrConst(eachWord[4].c_str());

					if (tempType != EMPTYTYPE)
					{
						if (tempType == CONS)
						{
							memLocRight = FindSymbol(atoi(eachWord[4].c_str()), tempType);
						}
						else
						{
							memLocRight = FindSymbol(eachWord[4][0], tempType);
						}

						if (memLocRight == -1)
						{
							TableEntry tempTable(0, tempType, memoryCounter);
							if (tempType == VAR)
							{
								tempTable.setSymbol(eachWord[4][0]);
							}
							else
							{
								tempTable.setSymbol(atoi(eachWord[4].c_str()));
								information->InsertInList(memoryCounter, (atoi(eachWord[4].c_str())));
							}
							Table.push_back(tempTable);
							success = true;
							memLocRight = memoryCounter;
							memoryCounter++;
						}

					}
					else
					{
						success = false;
						break;
					}
					//if ((FindSymbol(atoi(eachWord[2].c_str()), VAR) != -1) && (FindSymbol(atoi(eachWord[4].c_str()), VAR) != -1))
					//{

					int BranchTo = atoi(eachWord[6].c_str());

					/*
					if (FindSymbol(BranchTo, LINE) == -1)
					{
					//flags.push_back(BranchTo);
					flags[instructionCounter] = BranchTo;
					success = true;
					}*/

					if(eachWord[3] == "==")
					{
						instructions.push_back((LOAD * 1000) + memLocLeft);
						instructionCounter++;
						instructions.push_back((SUBTRACT * 1000) + memLocRight);
						instructionCounter++;
						flags[instructionCounter] = BranchTo;
						instructions.push_back(BRANCHZERO * 1000);
						instructionCounter++;
						success = true;
					}
					else if(eachWord[3] == "<=")
					{
						instructions.push_back((LOAD * 1000) + memLocLeft);
						instructionCounter++;
						instructions.push_back((SUBTRACT * 1000) + memLocRight);
						instructionCounter++;
						//flags.push_back(atoi(eachWord[6].c_str()));
						flags[instructionCounter] = BranchTo;
						instructions.push_back(BRANCHZERO * 1000);
						instructionCounter++;
						flags[instructionCounter] = BranchTo;
						instructions.push_back(BRANCHNEG * 1000);
						instructionCounter++;
						success = true;
					}
					else if (eachWord[3] == ">=")
					{
						instructions.push_back((LOAD * 1000) + memLocRight);
						instructionCounter++;
						instructions.push_back((SUBTRACT * 1000) + memLocLeft);
						instructionCounter++;
						flags[instructionCounter] = BranchTo;
						instructions.push_back(BRANCHZERO * 1000);
						instructionCounter++;
						flags[instructionCounter] = BranchTo;
						instructions.push_back(BRANCHNEG * 1000);
						instructionCounter++;
						success = true;
					}
					else if (eachWord[3] == "<")
					{
						instructions.push_back((LOAD * 1000) + memLocLeft);
						instructionCounter++;
						instructions.push_back((SUBTRACT * 1000) + memLocRight);
						instructionCounter++;
						//flags.push_back(atoi(eachWord[6].c_str()));
						flags[instructionCounter] = BranchTo;
						instructions.push_back(BRANCHNEG * 1000);
						instructionCounter++;
						success = true;
					}
					else if (eachWord[3] == ">")
					{
						instructions.push_back((LOAD * 1000) + memLocRight);
						instructionCounter++;
						instructions.push_back((SUBTRACT * 1000) + memLocLeft);
						instructionCounter++;
						flags[instructionCounter] = BranchTo;
						instructions.push_back(BRANCHNEG * 1000);
						instructionCounter++;
						success = true;
					}
					else if (eachWord[3] == "!=")
					{
						instructions.push_back((LOAD * 1000) + memLocRight);
						instructionCounter++;
						instructions.push_back((SUBTRACT * 1000) + memLocLeft);
						instructionCounter++;
						//flags.push_back(atoi(eachWord[6].c_str()));
						flags[instructionCounter] = BranchTo;
						instructions.push_back(BRANCHNEG * 1000);
						instructionCounter++;
						success = true;
					}
					else
					{
						success = false;
						break;
					}
					//}
				}
				else if (eachWord[index] == "goto")
				{ 
					if (eachWord.size() != 3)
					{
						success = false;
						break;
					}

					int BranchTo = atoi(eachWord[2].c_str());

					if (FindSymbol(BranchTo, LINE) == -1)
					{
						//flags.push_back(BranchTo);
						flags[instructionCounter] = BranchTo;
						success = true;
						instructions.push_back((BRANCH * 1000));
					}
					else
					{
						instructions.push_back((BRANCH * 1000) + FindSymbol(BranchTo, LINE));
					}
					instructionCounter++;
					success = true;
				}
				else if (eachWord[index] == "end")
				{
					instructions.push_back((HALT * 1000));
					success = true;
				}
				else
				{
					success = false;
					break;
				}
			}

			if (success == false)
			{
				break;
			}

			tableCounter++;
		}

		if (success == false)
		{
			break;
		}
	}
	return success;
}



/*What function does: Takes in a string that is the Simple code that the user entered, then puts each line
into a vector of strings. This is later broken up into individual words (in the
populateTable function) for analyzing.
Inputs: String that contains the Simple code that the user entered.
Outputs: None, besides a populated vector that contains each of the program lines, separated.
*/
void Compiler::setProgram( string newProgram )
{
	string temp;

	programLines.clear();
	isEnd = false;
	isFirstInstruction = true;
	statedAction = "";


	program = newProgram;

	for (int index = 0; index < program.length(); index++)
	{
		if (program[index] != '\n')
		{
			temp += program[index];
		}
		else
		{
			programLines.push_back(temp);
			temp.clear();
		}
	}

	programLines.push_back(temp);
}

/*What function does: Searches for a line number, constant, or variable in the table.
Inputs: The symbol you are looking for, and its type (to distinguish between constants and line numbers).
Outputs: If the symbol is found, its location in memory is returned. Else, -1 is returned to show that it
was not found. 
*/
int Compiler::FindSymbol( int Sym, int typ )
{
	for (int index = 0; index < Table.size(); index++)
	{
		if (Table[index].getType() == typ)
		{
			if (Table[index].getSymbol() == Sym)
			{
				return Table[index].getLocationOfSymbol();
			}
		}
	}

	return -1;
}

/*What function does: Determines if an item is a variable or a constant, depending whether it is a numeral or
if it is an alphabetical character. 
Inputs: The item you wish to analyze (in a string, in case it is a character).
Outputs: An integer corresponding to what the item is. 
*/
int Compiler::VarOrConst( string item )
{
	if (isalpha(item[0]))
	{
		return VAR;
	}
	else if ((atoi(item.c_str())) || (item[0] == '0'))
	{
		return CONS;
	}
	else
	{
		return EMPTYTYPE;
	}
}

/*What function does: Constructor for the compiler class. Initializes all of the important components.
Inputs: None.
Outputs: An initialized compiler. 
*/
Compiler::Compiler()
{
	this->accumulator = 0;
	this->DataMemLocation = 0;
	this->instructionCounter = 0;
	this->program = "";
	this->information = new topLists;
	this->currentInstruction = new TableEntry;
	this->isFirstInstruction = true;
	this->statedAction = "";
	this->isEnd = false;
	this->inputFromUser = 0;
	this->infixPostfixEvaluations = new Run;
}



/*What function does: Getter for the vector of simpletron instructions (which are technically only integers).
Inputs: None.
Outputs: A vector of integers that corresponds to the instructions. 
*/
vector<int> Compiler::getInstructions()
{
	return instructions;
}

/*What function does: Fixes the flags in the instructions and table by utilizing a map, which maps
one item to another for easy access and easy finding of the items. If the line
number that the branching is supposed to go to exists, then the instructions are 
fixed. Else, false is returned and the loop is broken out of. 
Inputs: None, besides the map of flags.
Outputs: True or false, depending on whether the flags were correct or not.
*/
bool Compiler::fixFlags()
{
	bool success = true;

	for( map<int,int>::iterator ii=flags.begin(); ii!=flags.end() && success; ++ii)
	{
		int f;
		f =FindSymbol((*ii).second, LINE);

		if (f == -1)
		{
			success = false;
			break;
		}
		else
		{
			instructions[(*ii).first] = ((instructions[(*ii).first] / 1000) * 1000) + f;
		}
	}

	return success;
}

/*What function does: Populates the vector of Simpletron classes, which divide the operation codes and 
operands into separate variables, which allows for easier interpretation.
Inputs: None, besides the vector of instructions already in place.
Outputs: None, besides a populated Simpletron vector.
*/
void Compiler::populateSimpletron()
{

	int locInMem = 0, nodeLocation = 0, decision = 0;
	int OperCode = EMPTY; 


	for (int i = 0; i < instructions.size(); i++)
	{
		locInMem = instructions[i] % 1000;
		OperCode = (instructions[i] / 1000);

		dividedInstructions.push_back(Simpletron(nodeLocation, OperCode, locInMem));

		nodeLocation++;
	}
}

/*What function does: Getter for the vector of table entries.
Inputs: None.
Outputs: Returns a vector that contains the table entries.
*/
vector<TableEntry> Compiler::getTable()
{
	return Table;
}

/*What function does: Essentially a "run" function. It takes the code that has been divided into its operation
code and operand, then executes the appropriate operation.
Inputs: None.
Outputs: None, though the variable isEnd may change depending on if there was an error or if the end of the
program has been reached.
*/
void Compiler::executionCode()
{
	int temp;
	bool branchOrNot = false;
	int check = 0;

	if (isFirstInstruction == true)
	{
		instructionCounter = 0;
		isFirstInstruction = false;
	}

	if (isEnd == false)
	{
		temp = dividedInstructions[instructionCounter].getOpCode();

		switch(temp)
		{
		case READ:
			read();
			break;
		case WRITE:
			write();
			break;
		case LOAD:
			load();
			break;
		case STORE:
			Store();
			break;
		case ADD:
			add();
			break;
		case SUBTRACT:
			subtract();
			break;
		case DIVIDE:
			divide();
			break;
		case MULTIPLY:
			multiply();
			break;
		case EXPO:
			expo();
			break;
		case MOD:
			mod();
			break;
		case BRANCH:
			branchOrNot = branch();
			break;
		case BRANCHNEG:
			branchOrNot = branchNeg();
			break;
		case BRANCHZERO:
			branchOrNot = branchZero();
			break;
		case HALT:
			isEnd = true;
			statedAction = "END OF EXECUTION.";
			break;
		default: 
			isEnd = true;
		}


		if ((temp != BRANCH) && (temp != BRANCHNEG) && (temp != BRANCHZERO))
		{
			instructionCounter++;
		}
		else
		{
			if (branchOrNot == false)
			{
				instructionCounter++;
			}
		}
	}
	else
	{
		statedAction = "END OF EXECUTION.";
	}
}

/*What function does: Converts an integer to a string.
Inputs: The number you wish to convert to a string.
Outputs: The string.
*/
string convertInt(int number)
{
	if (number == 0)
	{
		return "0";
	}

	string temp = "";
	string returnvalue = "";

	if (number < 0)
	{
		returnvalue = "-";
		number = number * -1;
	}
	while (number>0)
	{
		temp += number % 10 + 48;
		number /= 10;
	}

	for (int i=0; i < temp.length(); i++)
	{
		returnvalue += temp[temp.length() - i - 1];
	}

	return returnvalue;
}

/*What function does: Reads the user's input from the keyboard.
Inputs:	An integer number from the user.
Outputs: A changed space in memory (a new node in the data memory list is created).
*/
void Compiler::read()
{
	int newData = inputFromUser;

	information->InsertInList(dividedInstructions[instructionCounter].getOperand(), newData);

	statedAction = "Input from user has been stored.";
}

/*What function does: Prints an integer in a data memory spot to the screen.
Inputs: None, besides the place in memory from the instruction.
Outputs: An integer printed to the screen.
*/
void Compiler::write()
{
	int memValue = 0;

	memValue = information->returnDataVal(dividedInstructions[instructionCounter].getOperand());

	statedAction = "Value returned: ";
	statedAction += convertInt(memValue);

}

/*What function does: Loads an integer value from a memory spot into the accumulator.
Inputs: None, besides the integer value in the memory spot.
Outputs: None, besides a changed accumulator.
*/
void Compiler::load()
{
	int memValue = 0;

	memValue = information->returnDataVal(dividedInstructions[instructionCounter].getOperand());

	accumulator = memValue;

	statedAction = "Updated Accumulator: ";
	statedAction += convertInt(accumulator);
}

/*What function does: Stores the integer value in the accumulator into a new memory spot in the list.
Inputs: None, besides the accumulator.
Outputs: None, besides a new node in the data memory list.
*/
void Compiler::Store()
{
	information->InsertInList(dividedInstructions[instructionCounter].getOperand(), accumulator);

	statedAction = "Accumulator has been stored into memory.";
}

/*What function does: Adds the number in the accumulator to a number in a data memory spot, then stores the result in the accumulator.
Inputs:	None, besides the accumulator and number in the data memory spot.
Outputs: A modified accumulator.
*/
void Compiler::add()
{
	accumulator = accumulator + (information->returnDataVal(dividedInstructions[instructionCounter].getOperand()));

	statedAction = "Addition executed. Accumulator now equals ";
	statedAction += convertInt(accumulator);
	statedAction += ".";
}

/*What function does: Subtracts the number in the accumulator to a number in a data memory spot, then stores the result in the
accumulator.
Inputs:	None, besides the accumulator and number in the data memory spot.
Outputs: A modified accumulator.
*/
void Compiler::subtract()
{
	accumulator = accumulator - (information->returnDataVal(dividedInstructions[instructionCounter].getOperand()));

	statedAction = "Subtraction executed. Accumulator now equals ";
	statedAction += convertInt(accumulator);
	statedAction += ".";
}

/*What function does: Divide the number in the accumulator to a number in a data memory spot, then stores the result in the
accumulator.
Inputs:	None, besides the accumulator and number in the data memory spot.
Outputs: A modified accumulator.
*/
void Compiler::divide()
{
	if ((information->returnDataVal(dividedInstructions[instructionCounter].getOperand())) != 0)
	{
		accumulator = accumulator / (information->returnDataVal(dividedInstructions[instructionCounter].getOperand()));
		statedAction = "Division executed. Accumulator now equals ";
		statedAction += convertInt(accumulator);
		statedAction += ".";
	}
	else
	{
		statedAction = "This operation cannot be performed. Result undefined.";
		isEnd = true;
	}
}

/*What function does: Multiplies the number in the accumulator to a number in a data memory spot, then stores the result in the
accumulator.
Inputs:	None, besides the accumulator and number in the data memory spot.
Outputs: A modified accumulator.
*/
void Compiler::multiply()
{
	accumulator = accumulator * (information->returnDataVal(dividedInstructions[instructionCounter].getOperand()));

	statedAction = "Multiplication executed. Accumulator now equals ";
	statedAction += convertInt(accumulator);
	statedAction += ".";
}

/*What function does: Mods the number in the accumulator to a number in a data memory spot, then stores the result in the accumulator.
Inputs:	None, besides the accumulator and number in the data memory spot.
Outputs: A modified accumulator.
*/
void Compiler::mod()
{
	if (information->returnDataVal(dividedInstructions[instructionCounter].getOperand()) != 0)
	{
		accumulator = accumulator % (information->returnDataVal(dividedInstructions[instructionCounter].getOperand()));

		statedAction = "Modulus executed. Accumulator now equals ";
		statedAction += convertInt(accumulator);
		statedAction += ".";
	}
	else
	{
		statedAction = "This operation cannot be performed. Result undefined.";
		isEnd = true;
	}
}

/*What function does: Branches to another spot in the instruction list.
Inputs:	 None, besides the new spot in the instruction list.
Outputs: None, besides a modified instruction counter.
*/
bool Compiler::branch()
{	
	bool success = true;
	instructionCounter = dividedInstructions[instructionCounter].getOperand();

	statedAction = "Branching executed to appropriate instruction.";

	return success;
}

/*What function does: Branches to another spot in the instruction list if the accumulator is negative.
Inputs:	 None, besides the new spot in the instruction list.
Outputs: None, besides a modified instruction counter if the accumulator is negative.
*/
bool Compiler::branchNeg()
{
	bool success = false;

	if (accumulator < 0)
	{
		instructionCounter = dividedInstructions[instructionCounter].getOperand();

		statedAction = "Branching executed to appropriate instruction.";

		success = true;
	}
	else
	{
		statedAction = "Branching NOT executed. Accumulator not less than zero.";

	}

	return success;
}

/*What function does: Branches to another spot in the instruction list if the accumulator is zero.
Inputs:	 None, besides the new spot in the instruction list.
Outputs: None, besides a modified instruction counter if the accumulator is zero.
*/
bool Compiler::branchZero()
{
	bool success = false;

	if (accumulator == 0)
	{
		instructionCounter = dividedInstructions[instructionCounter].getOperand();

		statedAction = "Branching executed to appropriate instruction.";

		success = true;
	}
	else
	{
		statedAction = "Branching NOT executed. Accumulator not equal to zero.";
	}

	return success;
}

/*What function does: Takes the accumulator and raises it to the exponent of the value stored in a spot in memory. That number is
then stored back into the accumulator.
Inputs:	None, besides the accumulator and the number in the spot in memory.
Outputs: None, besides a modified accumulator.
*/
void Compiler::expo()
{
	double memValue = 0.0, holder = 0.0;
	memValue = (double)(information->returnDataVal(dividedInstructions[instructionCounter].getOperand()));
	holder = (pow(((double)(accumulator)), memValue));
	accumulator = (int)(holder);

	statedAction = "Exponentiation executed. Accumulator now equals ";
	statedAction += convertInt(accumulator);
	statedAction += ".";
}

/*What function does: Returns the bool variable that determines if the end of the function has been reached
(or if an error was encountered).
Inputs: None.
Outputs: True or false.
*/
bool Compiler::getIsEnd()
{
	return isEnd;
}

/*What function does: Determines if the current instruction needs input from the user. This is important so
the input text box can be utilized.
Inputs: None.
Outputs: True or false, depending on what the operation code of the current item is.
*/
bool Compiler::CurrentIsRead()
{
	bool isRead = false;

	if (dividedInstructions[instructionCounter].getOpCode() == READ)
	{
		isRead = true;
	}

	return isRead;
}

/*What function does: Setter for the input from the user.
Inputs: An integer that is the new data.
Outputs: None, besides an updated user input variable.
*/
void Compiler::setInputFromUser(int newData)
{
	inputFromUser = newData;
}

/*What function does: Getter for the user input.
Inputs: None.
Outputs: An integer that corresponds to the input from the user.
*/
int Compiler::getUserInput()
{
	return inputFromUser;
}

/*What function does: Getter for the stated action of the operation (allows for printing what happened to the
screen).
Inputs: None.
Outputs: A string.
*/
string Compiler::getStatedAction()
{
	return statedAction;
}

/*What function does: Getter for the variable that determines if the first instruction is being executed.
Inputs: None.
Outputs: True or false.
*/
bool Compiler::getIsFirstInstruction()
{
	return isFirstInstruction;
}

/*What function does: Setter for the instruction counter.
Inputs: An integer that corresponds to the new instruction counter.
Outputs: An updated instruction counter.
*/
void Compiler::setInstructionCounter( int newData )
{
	instructionCounter = newData;
}

/*What function does: Getter for the instruction counter.
Inputs: None.
Outputs: Returns an integer, which corresponds to the instruction counter.
*/
int Compiler::getInstructionCounter()
{
	return instructionCounter;
}

/*What function does: Gets the top of the pointer to the data memory (where all of the information is stored).
Inputs: None.
Outputs: A toplists pointer is returned.
*/
topLists * Compiler::getInformation()
{
	return information;
}

/*What function does: Getter for the accumulator.
Inputs: None.
Outputs: An integer corresponding to the accumulator.
*/
int Compiler::getAccumulator()
{
	return accumulator;
}

/*What function does: Getter for the instructions that contain the operation code and operands split into 
separate variables.
Inputs: None.
Outputs: A vector containing simpletron classes.
*/
vector<Simpletron> Compiler::getDividedInstructions()
{
	return dividedInstructions;
}