/*	Interpreter Pattern
*
*	This program is used to show how Interpreter pattern works.
*	In this program, Chinese math expression is interpreted in
*   this example.
*	
*   expression			::= number | AddOperation | SubstractOperation | MultifyOperation 
							| DiviveOperation | '(' expression ')'
*   AddOperation		::= expression '��' expression
*   SubstractOperation	::= expression '��' expression
*   MultifyOperation	::= expression '��' expression
*   DiviveOperation		::= expression '��' expression
*   Number				::= 'һ'|'��'|'��'|'��'|'��'|'��'|'��'|'��'|'��'
*
*   @ Wang Qiang  2010 NTU
*
*/

#include <iostream>
#include <string>
#include <map>
#include <stack>
using namespace std;

class ChineseExp{
public:
	ChineseExp();
	virtual ~ChineseExp();
	virtual double Interprete(map<string,int> myDict) = 0; // Here use map to implement the Context
};

class ChineseNum : public ChineseExp{
public:
	virtual ~ChineseNum();
	ChineseNum(string num);
	virtual double Interprete(map<string,int> myDict);
private:
	string numString;
};

class ChineseAdd : public ChineseExp{
public:
	virtual ~ChineseAdd();
	ChineseAdd(ChineseExp* left, ChineseExp* right);
	virtual double Interprete(map<string,int> myDict);
private:
	ChineseExp* leftOperator;
	ChineseExp* rightOperator;
};


class ChineseSub : public ChineseExp{
public:
	virtual ~ChineseSub();
	ChineseSub(ChineseExp* left, ChineseExp* right);
	virtual double Interprete(map<string,int> myDict);
private:
	ChineseExp* leftOperator;
	ChineseExp* rightOperator;
};

class ChineseMul : public ChineseExp{
public:
	virtual ~ChineseMul();
	ChineseMul(ChineseExp* left, ChineseExp* right);
	virtual double Interprete(map<string,int> myDict);
private:
	ChineseExp* leftOperator;
	ChineseExp* rightOperator;
};

class ChineseDiv : public ChineseExp{
public:
	virtual ~ChineseDiv();
	ChineseDiv(ChineseExp* left, ChineseExp* right);
	virtual double Interprete(map<string,int> myDict);
private:
	ChineseExp* leftOperator;
	ChineseExp* rightOperator;
};


//  Class Evaluator, construct the syntax tree This is not the part of Interpreter Pattern
class Evaluator{
public:
	~Evaluator();
	Evaluator();
	void Construct(string expression);
	double Interprete(map<string,int> myDict);
private:
	ChineseExp* myExpression;
	ChineseExp* ExpConstruct(stack<string>* numStack);
	int IsNumber(string tString);
};

