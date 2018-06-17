#include "../header/SortingSearchingAlgorithms.h"
#include <iostream>
#include <string>


void SortingSearchingAlgorithms::SortingSearchingMenu()
{
	system("CLS");
	int m_choice;
	do
	{
			system("CLS");
			std::cout << "\nTree DataStructure Problems" << std::endl;
			std::cout << "\n1) Bubble Sort" << std::endl;
			std::cout << "\n2) Insertion Sort" << std::endl;
			std::cout << "\n3) Quick Sort" << std::endl;
			std::cout << "\n4) Merge Sort" << std::endl;
			std::cout << "\n5) Print Nodes at KDistance from root" << std::endl;
			std::cout << "\nInput your choice\t";
			std::cin >> m_choice;
			switch (m_choice)
			{
			case 1:
				std::cout << "\nComing Soon" << std::endl;
				//root->InOrder(root);
				std::cout << std::endl;
				break;
			case 2:
				std::cout << "\nComing Soon" << std::endl;
				//TreeProblems::LevelOrderTraversal(root);
				std::cout << std::endl;
				break;
			case 3:
				std::cout << "\nMerge Sort" << std::endl;
				//TreeProblems::ReverseLevelOrderTraversal(root);
				std::cout << std::endl;
				break;
			case 4:
				std::cout << "\nQuick Sort" << std::endl;;
				std::cout << std::endl;
				break;
			case 5:
				std::cout << "\nPlease enter kDistance from root\t";
			//	std::cin >> m_input;
				std::cout << std::endl;
				break;
			}
	} while (m_choice != 99);
}


void SortingSearchingAlgorithms::MergeSort()
{
	std::cout << "\nFunction call for Quick Sort" << std::endl;;
}

		