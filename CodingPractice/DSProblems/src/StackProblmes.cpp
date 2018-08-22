#include "../header/Stackproblems.h"
#include <vector>
#include <stack>
#include <iostream>
/*





void StackProblesMenu()
{

}

void FindNextMaxInteger()
{

}

void RainTappingProblem()
{/

}

*/
long largestRectangle(std::vector<int> h) {

	if (h.size() <= 0)
		return 0;

	std::stack<int> m_stack;
	int m_maxarea = 0, i = 0;
	int m_stackTop, m_areaWithStackTop;

	//m_stack.push(0);

	while (i < h.size())
	{
		if (m_stack.empty() || h.at(i) >= h.at(m_stack.top()))
		{
			m_stack.push(i);
			i++;
		}
		else
		{
			int p = m_stack.top();
			m_stack.pop();
			int m_stackTop = h.at(p);
			int w = m_stack.empty() ? i : i - m_stack.top() - 1;
			int area = m_stackTop * w;
			if (area > m_maxarea)
				m_maxarea = area;
		}
	}


	while (m_stack.empty() == false)
	{
		int p = m_stack.top();
		m_stack.pop();
		int m_stackTop = h.at(p);
		int w = m_stack.empty() ? i : i - m_stack.top() - 1;
		int area = m_stackTop * w;
		if (area > m_maxarea)
			m_maxarea = area;
	}

	return m_maxarea;
}


void QueueUsingTwoStacks()
{
	long int m_QueriesNo, m_Operation, m_Input;
	std::cin >> m_QueriesNo;

	std::stack<int> m_StackOriginal, m_StackReversed;

	for (long int i = 0; i < m_QueriesNo; i++)
	{
		std::cin >> m_Operation;
		switch (m_Operation)
		{
		case 1:
		{
			std::cin >> m_Input;
			m_StackOriginal.push(m_Input);
		}
		break;

		case 2:
		{
			if (m_StackReversed.empty())
			{
				while (!m_StackOriginal.empty())
				{
					m_StackReversed.push(m_StackOriginal.top());
					m_StackOriginal.pop();
				}
			}

			m_StackReversed.pop();

		}
		break;
		case 3:
		{
			if (!m_StackReversed.empty())
			{
				std::cout << m_StackReversed.top() << std::endl;
			}
			else if (m_StackReversed.empty() && !m_StackOriginal.empty())
			{
				while (!m_StackOriginal.empty())
				{
					m_StackReversed.push(m_StackOriginal.top());
					m_StackOriginal.pop();
				}
				std::cout << m_StackReversed.top() << std::endl;
			}
		}
		break;
		}
	}
}
int equalStacks(std::vector<int> h1, std::vector<int> h2, std::vector<int> h3) {
		/*
		* Write your code here.
		*/
	int m_maxheight;
	int heightOfh1 = 0, heightOfh2 = 0, heightOfh3 = 0;
	int i = 0, j = 0, k = 0, iterator;

	for (auto& cyleinderHeight : h1)
		heightOfh1 += cyleinderHeight;
	for (auto& cyleinderHeight : h2)
		heightOfh2 += cyleinderHeight;
	for (auto& cyleinderHeight : h3)
		heightOfh3 += cyleinderHeight;


	while (1)
	{
		if (h1.size() == i || h2.size() == j || h3.size() == k)
		{
			m_maxheight = 0;
			break;
		}

		if (heightOfh1 == heightOfh2 && heightOfh2 == heightOfh3)
		{
			m_maxheight = heightOfh1;
			break;
		}

		if (heightOfh1 >= heightOfh2 && heightOfh1 >= heightOfh3) {
			heightOfh1 -= h1[i++];

		}
		else if (heightOfh2 >= heightOfh1 && heightOfh2 >= heightOfh3) {
			heightOfh2 -= h2[j++];

		}
		else if (heightOfh3 >= heightOfh2 && heightOfh3 >= heightOfh1) {
			heightOfh3 -= h3[k++];
		}

	}
	return m_maxheight;
}