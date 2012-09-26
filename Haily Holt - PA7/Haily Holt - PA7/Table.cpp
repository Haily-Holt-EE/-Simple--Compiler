#include "stdafx.h"
#include "Table.h"

TableEntry::TableEntry( int newSymbol , int newType, int newLocation)
{
	Symbol = newSymbol;
	TypeCode = (int)newType;
	Location = newLocation;
}

TableEntry::~TableEntry()
{

}

int TableEntry::getSymbol()
{
	return Symbol;
}

int TableEntry::getType()
{
	return TypeCode;
}

int TableEntry::getLocationOfSymbol()
{
	return Location;
}

void TableEntry::setSymbol( int newSymbol )
{
	Symbol = newSymbol;
}

void TableEntry::setType( int newType )
{
	TypeCode = newType;
}

void TableEntry::setLocationOfSymbol( int newLocation )
{
	Location = newLocation;
}



