/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mruggier <mruggier@student.42firenze.it    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/21 19:22:13 by mruggier          #+#    #+#             */
/*   Updated: 2024/07/21 19:22:14 by mruggier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"

RPN::RPN() {}
RPN::~RPN() {}
RPN::RPN(const RPN& rpn) { *this = rpn; }
RPN& RPN::operator=(const RPN& rpn) { if (this != &rpn) m_input = rpn.m_input; return *this; }

void RPN::Calculate(std::string str)
{
	m_input = str;
	try
	{
		parse();
		doOperations();
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
}

void RPN::doOperations()
{
	int check = 0;
	std::string::iterator it = m_input.begin();
	while (it != m_input.end())
	{
		if (*it != ' ')
		{
			if (*it == '+' || *it == '-' || *it == '*' || *it == '/')
			{
				if (check < 2)
					throw std::invalid_argument("Error: wrong order of operators and operands");
				int a = m_stack.top();
				m_stack.pop();
				int b = m_stack.top();
				m_stack.pop();
				if (*it == '+')
				{
					check--;
					m_stack.push(b + a);
					//std::cout << b << " + " << a << " = " << b + a << std::endl;
				}
				else if (*it == '-')
				{
					check--;
					m_stack.push(b - a);
					//std::cout << b << " - " << a << " = " << b - a << std::endl;
				}
				else if (*it == '*')
				{
					check--;
					m_stack.push(b * a);
					//std::cout << b << " * " << a << " = " << b * a << std::endl;
				}
				else if (*it == '/')
				{
					check--;
					if (a == 0)
						throw std::invalid_argument("Error: division by zero");
					m_stack.push(b / a);
					//std::cout << b << " / " << a << " = " << b / a << std::endl;
				}
			}
			else
			{
				m_stack.push(*it - '0');
				check++;
			}
		}
		it++;
	}
	if (m_stack.size() != 1)
		throw std::invalid_argument("Error: wrong order of operators and operands");
	std::cout << m_stack.top() << std::endl;
}

void RPN::parse()
{
	int nElements = 0;
	int nOperators = 0;
	std::string::iterator it = m_input.begin();
	while (it != m_input.end())
	{
		if ((*it < '0' || *it > '9') && *it != '+' && *it != '-' && *it != '*' && *it != '/' && *it != ' ')
			throw std::invalid_argument("Error: invalid character in input");
		
		if ((*it == ' ' && (*(it + 1) == ' ' || it + 1 == m_input.end() || it == m_input.begin()))
			|| (*it >= '0' && *it <= '9' && (*(it + 1) != ' ' || it + 1 == m_input.end()))
			|| (*it != ' ' && *it < '0' && *it > '9' && *(it + 1) == ' '))
			throw std::invalid_argument("Error: invalid character in input");

		if (*it == '+' || *it == '-' || *it == '*' || *it == '/')
			nOperators++;
		else if (*it >= '0' && *it <= '9')
			nElements++;

		it++;
	}
	if (nElements != nOperators + 1)
		throw std::invalid_argument("Error: wrong number of operators and operands");
}