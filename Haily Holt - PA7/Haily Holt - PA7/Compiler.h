#ifndef COMPILER_H
#define COMPILER_H

#include "topLists.h"
#include "Table.h"
#include "Simpletron.h"
#include "Fix.h"
#include <vector>
#include <map>
#include <cmath>

using std::vector;
using std::map;

class topLists;
class Run;

class Compiler
{
	friend class Run;
public:
	Compiler();
	bool populateTable();
	void setProgram (string newProgram);
	int FindSymbol(int Sym, int typ);
	int VarOrConst (string item);
	vector<int> getInstructions();
	vector<TableEntry> getTable();
	bool fixFlags ();
	void populateSimpletron();
	void executionCode();
	void read();
	void write();
	void load();
	void Store();
	void add();
	void subtract();
	void divide();
	void multiply();
	void mod();
	void expo();
	bool branch();
	bool branchNeg();
	bool branchZero();
	bool getIsEnd();
	bool CurrentIsRead();
	void setInputFromUser(int newData);
	int getUserInput();
	string getStatedAction();
	bool getIsFirstInstruction();
	void setInstructionCounter(int newData);
	int getInstructionCounter ();
	topLists *getInformation();
	int getAccumulator();
	vector<Simpletron> getDividedInstructions();
private:
	vector<TableEntry> Table;
	vector<int> instructions;
	map<int, int> flags;
	vector<Simpletron> dividedInstructions;
	string program;
	int accumulator;
	int instructionCounter;
	int DataMemLocation;
	topLists *information;
	vector<string> programLines;
	TableEntry *currentInstruction;
	bool isFirstInstruction;
	string statedAction;
	bool isEnd;
	int inputFromUser;
	Run *infixPostfixEvaluations;

};

string convertInt(int number);

#endif