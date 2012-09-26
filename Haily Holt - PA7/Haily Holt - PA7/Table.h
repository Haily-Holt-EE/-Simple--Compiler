#ifndef TABLE_H
#define TABLE_H

#include "DataMemory.h"


#define EMPTYTYPE 0
#define LINE 1
#define VAR 2
#define CONS 3

class TableEntry
{
public:
	TableEntry(int newSymbol = 0, int newType = EMPTYTYPE, int newLocation = 0);
	~TableEntry();
	int getSymbol();
	int getType();
	int getLocationOfSymbol();
	void setSymbol(int newSymbol);
	void setType(int newType);
	void setLocationOfSymbol(int newLocation);

private:
	int Symbol;
	int TypeCode;
	int Location;
};
#endif