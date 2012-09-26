#include "stdafx.h"
#include "topLists.h"

/*What function does: Constructor for the topLists class. Initializes each of its members.
Inputs: Values corresponding to each of the members of the class.
Outputs: None, besides an initialized class. 
*/
topLists::topLists( DataMemory *TopDat /*= NULL*/, DataMemory *TailDat /*= NULL*/ )
{
	topDat = TopDat;
	tailDat = TailDat;
}

/*What function does: Destructor for the topLists class. Deallocates memory for each of the nodes in the list. 
Inputs: None.
Outputs: A completely empty, deallocated list.
*/
topLists::~topLists()
{
	DataMemory *temp = NULL;

	while(tailDat != topDat)
	{
		temp = topDat;
		topDat = topDat->next;
		delete temp;
	}

	delete topDat;
}

/*What function does: Setter for the top pointer of the list.
Inputs: A pointer of DataMemory type.
Outputs: A top pointer that now points to the new pointer.
*/
void topLists::setTopDat( DataMemory *newPtr )
{
	topDat = newPtr;
}

/*What function does: Getter for the top data pointer. Returns what it is pointing to.
Inputs:	None.
Outputs: A variable of DataMemory* type that corresponds to what the top pointer of the list is pointing to.
*/
DataMemory * topLists::getTopDatPtr()
{
	return topDat;
}

/*What function does: Inserts a node into the data memory list, depending on its location in memory.
Inputs: The location and value to be inputted into the new node. 
Outputs: None, besides a modified list with the list node inserted somewhere in it.
*/
void topLists::InsertInList(int Location, int Val)
{
	DataMemory *prev = NULL, *curr = NULL, *ptr = NULL, *nextPtr = NULL;

	ptr = new DataMemory;
	ptr->setLocationInMemory(Location);
	ptr->setValue(Val);
	ptr->setNextPtr(nextPtr);

	if (topDat == NULL)
	{
		topDat = ptr;
		tailDat = ptr;
	}
	else
	{
		curr = topDat;

		while((curr != NULL) && (curr->locationInMemory < ptr->locationInMemory))
		{
			prev = curr;
			curr = curr->next;
		}

		if ((curr != NULL) && (curr->locationInMemory == ptr->locationInMemory))
		{
			curr->val = ptr->val;
		}
		else if (curr == NULL)
		{
			prev->next = ptr;
			tailDat = ptr;
		}
		else if (prev == NULL)
		{
			ptr->next = topDat;
			topDat = ptr;
		}
		else if ((curr != NULL) && (prev != NULL))
		{
			ptr->next = curr;
			prev->next = ptr;
		}
	}
}

/*What function does: Sets the tail pointer to a new pointer of DataMemory type.
Inputs: A pointer of DataMemory type.
Outputs: A tail pointer that points to the new pointer.
*/
void topLists::setTailDat( DataMemory *newPtr )
{
	tailDat = newPtr;
}

/*What function does: Getter for the tail pointer. Returns what it is pointing to.
Inputs: None.
Outputs: A DataMemory pointer that corresponds to what the tail is pointing to.
*/
DataMemory * topLists::getTailDatPtr()
{
	return tailDat;
}

/*What function does: Searches for a location of a node in the data memory list and returns its value.
Inputs: The location of the information (in the data memory...possible 1000 spots).
Outputs: Returns the integer value of the information in the located node. If a node is not located, then zero is returned.
*/
int topLists::returnDataVal( int Location )
{
	DataMemory *curr = NULL, *prev = NULL;
	int ValueToReturn = 0;

	if (topDat != NULL)
	{
		curr = topDat;

		while ((curr != NULL) && (curr->getLocationInMemory() != Location))
		{
			prev = curr;
			curr = curr->next;
		}

		if (curr != NULL)
		{
			ValueToReturn = curr->getVal();
		}
	}

	return ValueToReturn;
}

