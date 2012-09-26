#ifndef FIX_H
#define FIX_H

#define RIGHTP 1
#define LEFTP 2
#define OPER 3
#define NUMBER 4
#define ALPHA 5
#define ADDRES 6

#include <iostream>
#include <string>
#include "Compiler.h"
#include "Simpletron.h"

using std::cout;
using std::cin;
using std::string;
using std::endl;

class Compiler;

class FixItem
{
	friend class Run;
public:
	FixItem (int newType = 0, int newVal = 0);
	FixItem *makeNode (int Type, int Val);
	FixItem *getNextPtr ();
	void setNextPtr (FixItem *newFixItem);
	int getValue();
	void setValue(int newValue);
	int getType();
	void setType(int newType);

private:
	int type;
	int val;
	FixItem *next;
};

class Stack
{
public:
	Stack();
	void push (FixItem *data);
	FixItem *pop ();
	FixItem *peek ();
	FixItem *getNode();

private:
	FixItem *node;
};

class List
{
	friend class Run;
public:
	List();
	~List();
	void insertAtEnd (FixItem *newData);

private:
	FixItem *top;

};

class Run
{
	friend class Compiler;
public:
	Run();
	void parse (string inp);
	int operPrecedence (char first, char second);
	int operEqual (char first, char second);
	void postfixEval(Compiler *forPostFix, int assignLocation);
	int evaluationSwitch (char oper);
	void toPostfix ();
	Stack *getEvaluatedAnswer();

private:
	List *infix;
	List *postfix;
	Stack *evaluatedAnswer;
};


#endif