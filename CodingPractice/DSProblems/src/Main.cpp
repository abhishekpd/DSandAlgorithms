 #include <iostream>
#include "../header/TreeProblems.h"
#include "../header/ArrayProblems.h"
#include "../header/Stackproblems.h"
#include "../header/LLProblems.h"

 
int main()
{
	int m_choice = -1;

	do
	{
		system("CLS");
		std::cout << "Learning C++" << std::endl;
		std::cout << "DataStructure Problems" << std::endl;
		std::cout << "\n1) Tree Problems" << std::endl;
		std::cout << "\n2) Stack Problems" << std::endl;
		std::cout << "\n3) LinkedList Problmes" << std::endl;
		std::cout << "\n4) Array Problems " << std::endl;
		std::cout << "\n5) Queue Problems" << std::endl;
		std::cout << "\nInput your choice\t";
		std::cin >> m_choice;

		switch (m_choice)
		{
			case 1 : 
				TreeProblems::TreeOperationsMenu();
				break;
			case 2:
				StackProblesMenu();
				break;
			case 3:
				LLProblems::LLProblemsMenu();
				break;
			case 4:
				std::cout << "\nComing Soon" << std::endl;
				break;
			case 5:
				std::cout << "\nComing Soon" << std::endl;
				break;
			default :
				break;
		}
	} while (m_choice != 99);

/*	int array[] = {77,2,3,1,77,3,2,5,77,5};
	TreeNode *root = new TreeNode(5);
	root->Insert(3);
	root->Insert(2);
	root->Insert(4);
	root->Insert(9);
	root->Insert(7);
	root->Insert(10);

	//printRepeatatingNumbers(array, 10);

	//std::cout << "InOrder Traversal" << std::endl;
	//root->InOrder(root);
	
	//printKDistanceNode(root,3);
	//printRepeatatingNumbers(array, 10);
	//std::cout << "\nTree Level Order Traversal" << std::endl;
	//LevelOrderTraversal(root);
	//std::cout << "\nReverse Tree Level Order Traversal" << std::endl;
	//ReverseLevelOrderTraversal(root);
	///std::cout << "\nCount of Leaf Nodes In Tree -  " << NumberOfLeafNodesInTree(root) <<std::endl;

	//std::cout << "InOrder Traversal" << std::endl;
	//root->InOrder(root);
	std::cout << "\nHeight Of Binary Tree -  " << HeightOfBinaryTreeIterative(root) <<std::endl;

	*/
	return 0;
}