#ifndef SIMPLETRON_H
#define SIMPLETRON_H

#include "DataMemory.h"

#define EMPTY -1
#define READ 10
#define WRITE 11
#define LOAD 20
#define STORE 21
#define ADD 30
#define SUBTRACT 31
#define DIVIDE 32
#define MULTIPLY 33
#define EXPO 34
#define MOD 35
#define BRANCH 40
#define BRANCHNEG 41
#define BRANCHZERO 42
#define HALT 43


class Simpletron
{
	friend class Compiler;
public:
	Simpletron(int Location = 0, int operCode = EMPTY, int Operand = 0);
	~Simpletron();
	void setOpCode (int newCode);
	void setOperand (int newData);
	void setLocation (int newData);
	int getOpCode();
	int getOperand();
	int getLocation();
private:

	int location;
	int operationCode;
	int operand;
};
#endif