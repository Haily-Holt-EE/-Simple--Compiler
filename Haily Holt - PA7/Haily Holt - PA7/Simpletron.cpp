#include "stdafx.h"
#include "Simpletron.h"

/*What function does: Constructor for the Simpletron class. Initializes each of its members.
Inputs: Values for each of the class's members.
Outputs: None, besides an initialized class.
*/
Simpletron::Simpletron( int Location /*= 0*/, int operCode /*= EMPTY*/, int Operand /*= 0*/ )
{
	location = Location;
	operationCode = operCode;
	operand = Operand;
}

/*What function does: Destructor for the Simpletron class. Does nothing in this instance.
Inputs: None.
Outputs: None.
*/
Simpletron::~Simpletron()
{

}

/*What function does: Setter for the operational code. Sets it to a new operational code.
Inputs: A new operational code (which is an enumerated type).
Outputs: An operationCode variable with the newCode's value set to it.
*/
void Simpletron::setOpCode( int newCode )
{
	operationCode = newCode;
}

/*What function does: Setter for the operand. Sets the operand (place in memory) to a new integer value.
Inputs: An integer value corresponding to the new operand (place in memory).
Outputs: An operand variable that is assigned the value of the newData.
*/
void Simpletron::setOperand( int newData )
{
	operand = newData;
}

/*What function does: Getter for the operational code. Returns the operational code.
Inputs: None.
Outputs: Returns the enumerated type that operationCode contains.
*/
int Simpletron::getOpCode()
{
	return operationCode;
}

/*What function does: Getter for the operand. Returns an integer corresponding to a space in memory.
Inputs:	None.
Outputs: An integer value corresponding to a space in memory.
*/
int Simpletron::getOperand()
{
	return operand;
}

/*What function does: Setter for the location of a command in the list of commands.
Inputs: An integer value corresponding to the location of a command.
Outputs: A location variable that now contains the integer value of the new data.
*/
void Simpletron::setLocation( int newData )
{
	location = newData;
}

/*What function does: Getter for the location variable. Returns an integer corresponding to a location in the list of commands.
Inputs: None.
Outputs: An integer value corresponding to an integer in the list of commands.
*/
int Simpletron::getLocation()
{
	return location;
}