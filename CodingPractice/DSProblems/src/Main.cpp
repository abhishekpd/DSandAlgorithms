 #include <iostream>
#include "../header/TreeProblems.h"
#include "../header/ArrayProblems.h"
#include "../header/Stackproblems.h"
#include "../header/LLProblems.h"
#include "../header/SortingAlgorithm.h"
#include "../header/GeneralProblems.h"
 
int main()
{
	int m_choice = -1;

	do
	{
		system("CLS");
		std::cout << "Learning C++" << std::endl;
		std::cout << "DataStructure Problems" << std::endl;
		std::cout << "\n1) Tree Problems" << std::endl;
		std::cout << "\n2) Array Problems" << std::endl;
		std::cout << "\n3) LinkedList Problmes" << std::endl;
		std::cout << "\n4) Sorting & Searching Algorithm" << std::endl;
		std::cout << "\n5) General Data Structure Problems" << std::endl;
		std::cout << "\nInput your choice\t";
		std::cin >> m_choice;

		switch (m_choice)
		{
			case 1 : 
				TreeProblems::TreeOperationsMenu();
				break;
			case 2:
				ArrayProblems::ProblemsMenu();
				break;
			case 3:
				LLProblems::LLProblemsMenu();
				break;
			case 4:
				SortingAlgorithm::SortingAlgorithmMenu();
				break;
			case 5:
				GeneralProblems::ProblemsMenu();
				break;
			case 6:
				std::cout << "\nComing Soon" << std::endl;
				break;
			default :
				break;
		}
	} while (m_choice != 99);
	return 0;
}