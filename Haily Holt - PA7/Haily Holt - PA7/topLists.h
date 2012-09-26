#ifndef TOPLISTS_H
#define TOPLISTS_H

#include "Simpletron.h"

class topLists
{
public:
	topLists(DataMemory *TopDat = NULL, DataMemory *TailDat = NULL);
	~topLists();
	void setTopDat (DataMemory *newPtr);
	void setTailDat (DataMemory *newPtr);
	DataMemory *getTopDatPtr ();
	DataMemory *getTailDatPtr();
	void InsertInList (int Location, int Val);
	int returnDataVal (int Location);
private:
	DataMemory *topDat;
	DataMemory *tailDat;
};

#endif