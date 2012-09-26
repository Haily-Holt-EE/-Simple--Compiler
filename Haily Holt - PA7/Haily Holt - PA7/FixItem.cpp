#include "stdafx.h"
#include "Fix.h"

/*What function does: Constructor for FixItem class.
Inputs: None.
Outputs: Initialized class.
*/
FixItem::FixItem( int newType /*= 0*/, int newVal /*= 0*/)
{
	type = newType;
	val = newVal;
	next = NULL;
}

/*What function does: Creates nodes of FixItem* type. Used mostly to create nodes in the infix and postfix LISTS (I used lists instead
of character arrays so I could calculate numbers with more than one digit. Also used when pushing nodes to a stack.
Inputs: The type of item (number, operator, etc.) and its numerical value.
Outputs: A node of FixItem* type.
*/
FixItem * FixItem::makeNode( int Type, int Val )
{
	FixItem *ptr = new FixItem (Type, Val);
	return ptr;
}


FixItem * FixItem::getNextPtr()
{
	return next;
}

void FixItem::setNextPtr( FixItem *newFixItem )
{
	next = newFixItem;
}

int FixItem::getValue()
{
	return val;
}

void FixItem::setValue( int newValue )
{
	val = newValue;
}

int FixItem::getType()
{
	return type;
}

void FixItem::setType( int newType )
{
	type = newType;
}



List::~List()
{
	FixItem *temp;

	while(top != NULL)
	{
		temp = top;
		top = top->getNextPtr();
		delete temp;
	}

}
