/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mruggier <mruggier@student.42firenze.it    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/21 19:22:21 by mruggier          #+#    #+#             */
/*   Updated: 2024/07/21 19:22:22 by mruggier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
	RPN();
	~RPN();
	RPN(const RPN& rpn);
	RPN& operator=(const RPN& rpn);

	void Calculate(std::string str);
	void parse();
	void doOperations();
};

#endif