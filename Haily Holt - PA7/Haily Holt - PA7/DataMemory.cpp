#include "stdafx.h"
#include "DataMemory.h"

/*What function does: Constructor for the DataMemory class. Initializes its components.
Inputs: Data for each of the components.
Outputs: An initialized class.
*/
DataMemory::DataMemory( int LocationInMemory /*= 0*/, int Value /*= 0*/, DataMemory *Next /*= NULL*/ )
{
	locationInMemory = LocationInMemory;
	val = Value;
	next = Next;
}

/*What function does: Destructor. Is not needed for this class.
Inputs: N/A
Outputs: N/A
*/
DataMemory::~DataMemory()
{

}

/*What function does: Sets the location in memory of a node.
Inputs: An integer value.
Outputs: None, besides a modified location in memory. 
*/
void DataMemory::setLocationInMemory( int newLocation )
{
	locationInMemory = newLocation;
}

/*What function does: Sets the number value in a node.
Inputs: An integer value.
Outputs: A modified val.
*/
void DataMemory::setValue( int newVal )
{
	val = newVal;
}

/*What function does: Sets the next pointer to a new data memory.
Inputs: A DataMemory pointer.
Outputs: A modified next variable.
*/
void DataMemory::setNextPtr( DataMemory *Next )
{
	next = Next;
}

/*What function does: Getter for the location in memory of a node.
Inputs: None.
Outputs: The location in memory.
*/
int DataMemory::getLocationInMemory()
{
	return locationInMemory;
}

/*What function does: Getter for the integer value of a node.
Inputs: None.
Outputs: The value of the node.
*/
int DataMemory::getVal()
{
	return val;
}

/*What function does: Getter for the next pointer of a node.
Inputs: None.
Outputs: Returns what the next pointer of the node is pointing to.
*/
DataMemory * DataMemory::getNextPtr()
{
	return next;
}

