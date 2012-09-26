#include "stdafx.h"
#include "Fix.h"

/*What function does: Puts nodes on top of the stack.
Inputs: A stack and a node of FixItem* type. 
Outputs: A modified stack (with a new node on its top).
*/
void Stack::push( FixItem *data )
{
	if ((this->node != NULL) && (this->node->getType() != 0))
	{
		data->setNextPtr(this->node);
		this->node = data;
	}
	else
	{
		this->node = data;
	}
}

/*What function does: Takes items off of the top of a stack.
Inputs: A stack.
Outputs: Returns the data that was taken off of the top of the stack (a node of FixItem* type).
*/
FixItem * Stack::pop()
{
	FixItem *temp = NULL;

	if (this->node != NULL)
	{
		temp = this->node;
		this->node = this->node->getNextPtr();
		temp->setNextPtr(NULL);
		return temp;
	}

	return NULL;
}

/*What function does: Returns the data at the top of a stack.
Inputs: A stack.
Outputs: Returns the top of the stack (a node of FixItem* type). 
*/
FixItem * Stack::peek()
{
	return this->node;
}

FixItem * Stack::getNode()
{
	return node;
}

/*What function does: Constructor for Stack class.
Inputs: None.
Outputs: Initialized class.
*/
Stack::Stack()
{
	node = new FixItem();
}


