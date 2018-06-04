#include <stdio.h>
#include <stdlib.h>
#include <queue>
#include <stack>
#include <limits>
#include "../header/TreeNode.h"
#include "../header/TreeProblems.h"

void TreeOperationsMenu()
{
	system("CLS");
	int m_choice = -1,m_input;
	TreeNode *root = new TreeNode(5);
	root->Insert(3);
	root->Insert(2);
	root->Insert(4);
	root->Insert(9);
	root->Insert(7);
	root->Insert(10);

	do
	{
		system("CLS");
		std::cout << "\nTree DataStructure Problems" << std::endl;
		std::cout << "\n1) InOrder Traversal" << std::endl;
		std::cout << "\n2) Level Order Traversal" << std::endl;
		std::cout << "\n3) ReverseLevelOrderTraversal" << std::endl;
		std::cout << "\n4) Number Of Leaf Nodes" << std::endl;
		std::cout << "\n5) Print Nodes at KDistance from root" << std::endl;
		std::cout << "\n6) Height Of Binary Tree Iterative" << std::endl;
		std::cout << "\nInput your choice\t";
		std::cin >> m_choice;

		switch (m_choice)
		{
				
			case 1:
				std::cout << "\nInOrder Traversal" << std::endl;
				root->InOrder(root);
				std::cout << std::endl;
				break;
			case 2:
				std::cout << "\nLevel Order Traversal of Tree" << std::endl;
				LevelOrderTraversal(root);
				std::cout << std::endl;
				break;
			case 3:
				std::cout << "\nReverse Tree Level Order Traversal" << std::endl;
				ReverseLevelOrderTraversal(root);
				std::cout << std::endl;
				break;
			case 4:
				std::cout << "\nNo of leaf nodes in given binary tree\t" << NumberOfLeafNodesInTree(root); 
				std::cout << std::endl;
				break;
			case 5:
				std::cout << "\nPlease enter kDistance from root\t";
				std::cin >> m_input;
				printKDistanceNode(root, m_input);
				std::cout << std::endl;
				break;
			case 6:
				std::cout << "\nHeight of given binary tree\t" << HeightOfBinaryTreeIterative(root);
				std::cout << std::endl;
				break;
		}
		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		std::cin.get();
	} while (m_choice != 99);
}

void LevelOrderTraversal(TreeNode *root)
{
	std::queue<TreeNode *> m_queue;
	TreeNode* iternator_node;
	m_queue.push(root);

	while (!m_queue.empty())
	{
		iternator_node = m_queue.front();
		std::cout << "\t" << iternator_node->getNodeData();
		
		if (iternator_node->getLeftNode())
			m_queue.push(iternator_node->getLeftNode());
		if (iternator_node->getRightNode())
			m_queue.push(iternator_node->getRightNode());

		m_queue.pop();
	}
}

void ReverseLevelOrderTraversal(TreeNode *root)
{
	std::stack<TreeNode*> m_stack;
	std::queue<TreeNode*> m_queue;
	TreeNode* iterator_node;
	m_queue.push(root);

	while (!m_queue.empty())
	{
		iterator_node = m_queue.front();
		if (iterator_node->getRightNode())
			m_queue.push(iterator_node->getRightNode());
		if (iterator_node->getLeftNode())
			m_queue.push(iterator_node->getLeftNode());
	
		m_stack.push(iterator_node);
		m_queue.pop();
	}
	while (!m_stack.empty())
	{
		iterator_node = m_stack.top();
		std::cout << "\t" << iterator_node->getNodeData();
		m_stack.pop();
	}
}

int NumberOfLeafNodesInTree(TreeNode *root)
{
	std::queue<TreeNode *> m_queue;
	TreeNode *iterator_node;
	int count = 0;
	m_queue.push(root);
	
	while (!m_queue.empty())
	{
		iterator_node = m_queue.front();
		if (iterator_node->getLeftNode())
			m_queue.push(iterator_node->getLeftNode());
		if (iterator_node->getRightNode())
			m_queue.push(iterator_node->getRightNode());

		if ((iterator_node->getLeftNode() == NULL) && (iterator_node->getRightNode() == NULL))
			count++;
		m_queue.pop();
	
	}
	return count;
}


void printKDistanceNode(TreeNode* root, int klevel)
{
	if (klevel > HeightOfBinaryTreeIterative(root))
	{
		std::cout << "\nHeight of tree is less than distance entered, returning" << std::endl;
		return;
	}

	std::queue<TreeNode *> m_queue;
	int level = 1;
	m_queue.push(root);
	m_queue.push(NULL);

	while (!m_queue.empty()) {
		TreeNode *iternator_node = m_queue.front();

		if (level == klevel && iternator_node != NULL)
		{
			std::cout << "\t" << iternator_node->getNodeData();
		}
		m_queue.pop();
		if (iternator_node == NULL)
		{
			if (m_queue.front()) {
				m_queue.push(NULL);
			}
			level += 1;
			if (level > klevel)
					break;
		}
		else {
			if (iternator_node->getLeftNode())
				m_queue.push(iternator_node->getLeftNode());
			if (iternator_node->getRightNode())
				m_queue.push(iternator_node->getRightNode());
		}
	}
	std::cout << std::endl;
}


int HeightOfBinaryTreeIterative(TreeNode *root)
{
	std::queue<TreeNode *> m_queue;
	int treeHeight = 0;

	if (root == NULL)
		return 0;

	m_queue.push(root);

	while (1)
	{
		int nodeCount = m_queue.size();
		if (nodeCount == 0)
			break;

		++treeHeight;

		while (nodeCount > 0)
		{
			TreeNode *iterator_node = m_queue.front();
			if (iterator_node->getLeftNode())
				m_queue.push(iterator_node->getLeftNode());
			if (iterator_node->getRightNode())
				m_queue.push(iterator_node->getRightNode());

			m_queue.pop();
			nodeCount--;
		}
	}

	return treeHeight;
}
