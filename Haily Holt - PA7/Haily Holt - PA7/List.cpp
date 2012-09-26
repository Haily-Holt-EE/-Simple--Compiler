#include "stdafx.h"
#include "Fix.h"

/*What function does: Inserts a node at the end of a LIST. This is used when entering the original equation into a list, and also when
                      modifying it into the postfix expression. 
Inputs: A list, and a node of FixItem* type. 
Outputs: A list with the new node attached to the end. 
*/
void List::insertAtEnd( FixItem *newData )
{
	FixItem *temp = this->top;

	if(temp == NULL)
	{
		this->top = newData;
		return;
	}

	while (temp->getNextPtr() != NULL)
	{
		temp = temp->getNextPtr();
	}

	temp->setNextPtr(newData);
}

/*What function does: Constructor for List class.
Inputs: None.
Outputs: Initialized class.
*/
List::List()
{
	top = NULL;
}
