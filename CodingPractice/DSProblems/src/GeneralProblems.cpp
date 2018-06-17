#include <iostream>
#include "../header/GeneralProblems.h"

void GeneralProblems::ProblemsMenu()
{
	system("CLS");
	int m_choice = -1, m_input;
	int m_inputArray[] = { -2, -3, 4, -1, -2, 1, 5, -3 };
	do
	{
		system("CLS || clear");
		std::cout << "\nGeneral DataStructure Problems" << std::endl;
		std::cout << "\n1) Maximum Water Trapping Problem" << std::endl;
		std::cout << "\n2) Peak element in an Array" << std::endl;
		std::cout << "\n3) Largest Sum of Contiguous Subarray" << std::endl;
		std::cout << "\nInput your choice\t";
		std::cin >> m_choice;

		switch (m_choice)
		{

		case 1:
			std::cout << "\nMaximum Water Trapping Problem" << std::endl;
			GeneralProblems::RainWaterTrapping(m_inputArray, (sizeof(m_inputArray) / sizeof(m_inputArray[0])));
			std::cout << std::endl;
			break;
		case 2:
			std::cout << "\n" << std::endl;
			break;
		case 3:
			std::cout << "\nLargest Sum of Contiguous Subarray Solution" << std::endl;
			break;
		case 4:
			//std::cout << "\nNo of leaf nodes in given binary tree\t" << NumberOfLeafNodesInTree(root);
			std::cout << std::endl;
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

void GeneralProblems::RainWaterTrapping(int m_input[], int size)
{
	int m_TallestLeftSide[12], m_TallestRideSide[12];

	int m_MaxWater = 0;
	m_TallestLeftSide[0] = m_input[0];

	for (int i = 0; i < size; i++) {
		m_TallestLeftSide[i] = (m_TallestLeftSide[i - 1] > m_input[i]) ? m_TallestLeftSide[i - 1] : m_input[i];
	}
	m_TallestRideSide[size - 1] = m_input[size - 1];

	for (int i = size - 2; i>0; i--) {
		m_TallestRideSide[i] = (m_TallestRideSide[i - 1] > m_input[i]) ? m_TallestRideSide[i - 1] : m_input[i];
	}

}
