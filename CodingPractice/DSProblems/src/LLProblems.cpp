#include <iostream>
#include <stdlib.h>
#include "../header/LLNode.h"
#include "../header/LLProblems.h"

void LLProblems::LLProblemsMenu()
{
	system("CLS");
	int m_choice = -1, m_input;
	LLNode *head = new LLNode(5);
	head->Insert(3);
	head->Insert(2);
	head->Insert(4);
	head->Insert(9);
	head->Insert(7);
	head->Insert(10);

	do
	{
		system("CLS || clear");
		std::cout << "\nLL DataStructure Problems" << std::endl;
		std::cout << "\n1) LL Traversal" << std::endl;
		std::cout << "\n2) Reverse Linked List" << std::endl;
		std::cout << "\n3) Detect Loop in LL" << std::endl;
		std::cout << "\nInput your choice\t";
		std::cin >> m_choice;

		switch (m_choice)
		{

		case 1:
			std::cout << "\nLL Traversal" << std::endl;
			LLNode::TraverseLL(head);
			std::cout << std::endl;
			break;
		case 2:
			std::cout << "\nReverse LL with Interative method" << std::endl;
			head = LLProblems::ReverseLLWithOutRecursion(head);
			std::cout << std::endl;
			break;
		case 3:
			std::cout << "\nDetect Loop/Cycle in given LL" << std::endl;
			(LLProblems::DetectLoopInLL(head) == true) ? std::cout << "Loop Exists" :  std::cout << "Loop doesn't exist";
			std::cout << std::endl;
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


LLNode* LLProblems::ReverseLLWithOutRecursion(LLNode *head)
{
	if (head == nullptr)
		return nullptr;

	LLNode *m_prev, *m_current, *m_next;
	m_current = head;
	m_prev = nullptr;
	while (m_current != nullptr)
	{
		m_next= m_current->GetNextNode();
		m_current->SetNextNode(m_prev);
		m_prev = m_current;
		m_current = m_next;
	}
	return m_prev;
}

bool LLProblems::DetectLoopInLL(LLNode *head)
{
	LLNode *m_slowptr, *m_fastptr;
	m_slowptr =head;
	m_fastptr = head->GetNextNode();

	if (head == nullptr)
		return false;

	while (m_fastptr != nullptr && m_fastptr->GetNextNode() != nullptr && m_slowptr != nullptr)
	{
		if (m_fastptr == m_slowptr) {
			std::cout << "\nLoop Exisit in the given LL" << std::endl;
			return true;
		}
		m_slowptr = m_slowptr->GetNextNode();
		m_fastptr = m_fastptr->GetNextNode()->GetNextNode();
	}
	return false;
}