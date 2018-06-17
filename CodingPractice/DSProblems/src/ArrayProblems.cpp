#include "../header/ArrayProblems.h"
#include <stack>  
#include <iostream>

void ArrayProblems::ProblemsMenu()
{
	system("CLS");
	int m_choice = -1, m_input;
	int m_inputArray[] = { -2, -3, 4, -1, -2, 1, 5, -3 };
	do
	{
		system("CLS || clear");
		std::cout << "\nGeneral DataStructure Problems" << std::endl;
		std::cout << "\n1) Next Greater Element in Array" << std::endl;
		std::cout << "\n2) Find pivot in a sorted rotated array - Iterative Method" << std::endl;
		std::cout << "\n3) Largest Sum of Contiguous Subarray" << std::endl;
		std::cout << "\nInput your choice\t";
		std::cin >> m_choice;

		switch (m_choice)
		{

		case 1:
			std::cout << "\nNext Greater Element in Array" << std::endl;
			ArrayProblems::NextGreaterElementInGivenArray(m_inputArray, 12);
			std::cout << std::endl;
			break;
		case 2:
		{
			std::cout << "\nFind pivot in a sorted rotated array - Iterative" << std::endl;
			int m_inputArr[] = { 73,85,94,21,27,34,47,54,66 };
			ArrayProblems::FindPivotInSortedArrayBruteForce(m_inputArr, (sizeof(m_inputArr) / sizeof(m_inputArr[0])));
			std::cout << std::endl;
		}
			break;
		case 3:
			std::cout << "\nLargest Sum of Contiguous Subarray Solution" << std::endl;
			ArrayProblems::MaxmimSubArrayKadanesAlgorithm(m_inputArray, (sizeof(m_inputArray) / sizeof(m_inputArray[0]) ));
			break;
		case 4:
		{
			std::cout << "\nNo of leaf nodes in given binary tree\t";
			int m_inputArr[] = { 73,85,94,21,27,34,47,54,66 };
			ArrayProblems::FindPivotInSortedArrayWithBinarySearch(m_inputArr, (sizeof(m_inputArr) / sizeof(m_inputArr[0]));
		}
			break;
		case 5:
			std::cout << "\nPlease enter kDistance from root\t";
			std::cin >> m_input;
			//printKDistanceNode(root, m_input);
			std::cout << std::endl;
			break;
		case 6:
			//std::cout << "\nHeight of given binary tree\t" << HeightOfBinaryTreeIterative(root);
			std::cout << std::endl;
			break;
		}
		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		std::cin.get();
	} while (m_choice != 99);
}


void ArrayProblems::printRepeatatingNumbers(int array[], int size)
{
	int i = 0;
	std::cout << "\nRepeatating numbers in Array are\n";
	for (i = 0; i < size; i++)
	{
		if (array[abs(array[i])] >= 0) // check value of array index,if positive then make it negative 
		{
			array[abs(array[i])] = -array[abs(array[i])];
		}
		else if (array[abs(array[i])] < 0) // check value of array index,if negative then we have already encountered value and it's repetating
		{
			std::cout << "\t" << abs(array[i]);
		}
	}
}


void ArrayProblems::NextGreaterElementInGivenArray(int m_array[], int size)
{
	std::stack<int> m_stack;
	m_stack.push(m_array[0]);

	for (int i = 1; i < size; i++)
	{
		int next = m_array[i];
		
		if (!m_stack.empty())
		{
			int current = m_stack.top();
			m_stack.pop();
			while (next > current) {
				std::cout << current << "\tnext greater element in the " << next << std::endl;;
				if (m_stack.empty())
					break;
				current = m_stack.top();
				m_stack.pop();
			}			
			if (current > next)
				m_stack.push(current);
		}
		m_stack.push(m_array[i]);
	}

	while (!m_stack.empty())
	{
		std::cout << m_stack.top() << "\thas no greater element next to it" << std::endl;;
		m_stack.pop();
	}
}

void ArrayProblems::MaxmimSubArrayKadanesAlgorithm(int m_input[], int size)
{
	int maxSum = m_input[0];
	int currentSum = m_input[0];

	for (int i = 1; i < size; i++)
	{
		(currentSum + m_input[i]) > m_input[i] ? (currentSum = currentSum + m_input[i]) : (currentSum = m_input[i]);

		if (currentSum > maxSum)
			maxSum = currentSum;
	}

	std::cout << "Largest Sum of Contiguous Subarray -->\t" << maxSum << std::endl;
}


void ArrayProblems::FindPivotInSortedArrayBruteForce(int m_input[],int size)
{
	int m_pivot = 0;

	for (int i = 0; i < size; i++)
	{
		if (m_input[i + 1] < m_input[i]) {
			m_pivot = i + 1;
			break;
		}
	}
	std::cout << "Array is roatated at Index -->\t" << m_pivot <<  "\t with element --> "<< m_input[m_pivot] <<  std::endl;
}

void ArrayProblems::FindPivotInSortedArrayWithBinarySearch(int m_input[], int size)
{

}