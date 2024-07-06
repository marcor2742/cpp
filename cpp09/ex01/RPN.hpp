#ifndef RPN_HPP
#define RPN_HPP

#include <iostream>
#include <stack>

#define plus -5
#define minus -3
#define mult -6
#define div -1

class RPN
{
private:
	std::string m_input;
	std::stack<int> m_stack;

public:
	RPN() {}
	~RPN() {}
	RPN(const RPN& rpn) { (void)rpn; }
	RPN& operator=(const RPN& rpn) { (void)rpn; return *this; }

	void Calculate(std::string str);
	void parse();
	void doOperations();
};

#endif