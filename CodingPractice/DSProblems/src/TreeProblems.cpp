#include <stdio.h>
#include <stdlib.h>
#include <queue>
#include <stack>
#include <limits>
#include <map>
#include <unordered_map>
#include "../header/TreeNode.h"
#include "../header/TreeProblems.h"

void TreeProblems::TreeOperationsMenu()
{
	system("CLS");
	int m_choice = -1,m_input;
	int L_maxLevel,R_maxLevel;
	TreeNode *root = new TreeNode(5);
	root->Insert(3);
	root->Insert(2);
	root->Insert(4);
	root->Insert(9);
	root->Insert(7);
	root->Insert(10);
	root->Insert(12);
	root->Insert(14);

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
		std::cout << "\n7) Left view Of Binary Tree Iterative" << std::endl;
		std::cout << "\n8) Right view Of Binary Tree Iterative" << std::endl;
		std::cout << "\n9) Count Half Nodes in Binary Tree Iterative" << std::endl;
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
				TreeProblems::LevelOrderTraversal(root);
				std::cout << std::endl;
				break;
			case 3:
				std::cout << "\nReverse Tree Level Order Traversal" << std::endl;
				TreeProblems::ReverseLevelOrderTraversal(root);
				std::cout << std::endl;
				break;
			case 4:
				std::cout << "\nNo of leaf nodes in given binary tree\t" << TreeProblems::NumberOfLeafNodesInTree(root);
				std::cout << std::endl;
				break;
			case 5:
				std::cout << "\nPlease enter kDistance from root\t";
				std::cin >> m_input;
				printKDistanceNode(root, m_input);
				std::cout << std::endl;
				break;
			case 6:
				std::cout << "\nHeight of given binary tree\t" << TreeProblems::HeightOfBinaryTreeIterative(root);
				std::cout << std::endl;
				break;
			case 7:
				std::cout << "\nLeft view of given binary tree\t" << std::endl;
				L_maxLevel = 0;
				TreeProblems::LeftViewOfTree(root, 1, &L_maxLevel);
				std::cout << std::endl;
				break;
			case 8:
				std::cout << "\nRight view of given binary tree\t" << std::endl;
				R_maxLevel = 0;
				TreeProblems::RightViewOfTree(root, 1, &R_maxLevel);
				std::cout << std::endl;
				break;
			case 9:
				std::cout << "\nHalfNodes in given binary tree\t" << TreeProblems::CountHalfNodesInATree(root);
				std::cout << std::endl;
				break;
			case 10:
				std::cout << "Top View of a given binary tree" << std::endl;
				//TreeProblems::TopViewOfTree(root);
				break;
		}
		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		std::cin.get();
	} while (m_choice != 99);
}

void TreeProblems::LevelOrderTraversal(TreeNode *root)
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

void TreeProblems::ReverseLevelOrderTraversal(TreeNode *root)
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

int TreeProblems::NumberOfLeafNodesInTree(TreeNode *root)
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


void TreeProblems::printKDistanceNode(TreeNode* root, int klevel)
{
	if (klevel > TreeProblems::HeightOfBinaryTreeIterative(root))
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


int TreeProblems::HeightOfBinaryTreeIterative(TreeNode *root)
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

TreeNode* TreeProblems::LowestCommonAncestor(TreeNode *root,int NodeA,int NodeB)
{
	if (root == nullptr) {
		return nullptr;
	}

	if ((root->getNodeData() == NodeA) || (root->getNodeData() == NodeB))
		return root;

	TreeNode *leftChild = TreeProblems::LowestCommonAncestor(root->getLeftNode(), NodeA, NodeB);
	TreeNode *rightChild = TreeProblems::LowestCommonAncestor(root->getRightNode(), NodeA, NodeB);

	if (leftChild != nullptr && rightChild != nullptr)
		return root;

	if (leftChild == nullptr)
		return rightChild;
	else
		return leftChild;
}

void TreeProblems::LeftViewOfTree(TreeNode *root,int curren_level,int *max_level)
{
	if (root == nullptr)
		return;

	if (*max_level < curren_level)
	{
		std::cout << "\t" << root->getNodeData();
			*max_level = curren_level;
	}

	TreeProblems::LeftViewOfTree(root->getLeftNode(), curren_level + 1, max_level);
	TreeProblems::LeftViewOfTree(root->getRightNode(), curren_level + 1, max_level);
}

void TreeProblems::RightViewOfTree(TreeNode *root, int current_level, int *max_level)
{
	if (root == nullptr)
		return;
	if (*max_level  < current_level)
	{
		std::cout << "\t" << root->getNodeData();
		*max_level = current_level;
	}

	TreeProblems::RightViewOfTree(root->getRightNode(), current_level+1, max_level);
	TreeProblems::RightViewOfTree(root->getLeftNode(), current_level+1, max_level);
}


int TreeProblems::CountHalfNodesInATree(TreeNode *root)
{
	std::queue<TreeNode *> m_queue;
	TreeNode *iterator_node;
	int m_count = 0;

	if (root == nullptr)
		return 0;

	m_queue.push(root);

	while (!m_queue.empty())
	{
		iterator_node = m_queue.front();
		if (iterator_node->getLeftNode())
			m_queue.push(iterator_node->getLeftNode());
		if (iterator_node->getRightNode())
			m_queue.push(iterator_node->getRightNode());

		if ((iterator_node->getLeftNode() != nullptr && iterator_node->getRightNode() == nullptr) ||
			(iterator_node->getLeftNode() == nullptr && iterator_node->getRightNode() != nullptr))
		{
			m_count++;
		}

		m_queue.pop();
	}
	return m_count;
}

/*
void TreeProblems::TopViewOfTree(TreeNode *root)
{
	if (root == NULL)
		return;

	std::unordered_map<int, int> m_unorderedMap;
	std::queue< std::pair<TreeNode *, int> > m_Queue;

	m_Queue.push(std::make_pair(root, 0));

	while (!m_Queue.empty())
	{
		std::pair<TreeNode*, int> m_IteratorPair = m_Queue.front();
		TreeNode *iterator_node = m_IteratorPair.first;
		int m_distance = m_IteratorPair.second;

		if (m_unorderedMap.find(m_distance) == m_unorderedMap.end())
		{
			m_unorderedMap.insert(m_distance, iterator_node->getNodeData());
			std::cout << "\t" << iterator_node->getNodeData();
		}

		if(iterator_node->getLeftNode() != nullptr)
			m_Queue.push(std::make_pair(iterator_node->getLeftNode(), m_distance-1));

		if (iterator_node->getRightNode() != nullptr)
			m_Queue.push(std::make_pair(iterator_node->getRightNode(), m_distance + 1));

		m_Queue.pop();
	}
}
*/