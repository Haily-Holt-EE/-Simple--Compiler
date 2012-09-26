#ifndef DATAMEMORY_H
#define DATAMEMORY_H

#include <iostream>
#include <string>

using std::cout;
using std::cin;
using std::endl;
using std::ostream;
using std::string;

class DataMemory
{
	friend class Compiler;
	friend class topLists;
public:
	DataMemory(int LocationInMemory = 0, int Value = 0, DataMemory *Next = NULL);
	~DataMemory();
	void setLocationInMemory(int newLocation);
	void setValue (int newVal);
	void setNextPtr (DataMemory *Next);
	int getLocationInMemory ();
	int getVal();
	DataMemory *getNextPtr();
private:
	int locationInMemory;
	int val;
	DataMemory *next;
};

#endif