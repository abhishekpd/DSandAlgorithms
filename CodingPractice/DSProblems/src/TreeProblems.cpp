#include <stdio.h>
#include <stdlib.h>
#include <queue>
#include <stack>
#include <limits>
#include <map>
#include <unordered_map>
#include <utility> 
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
	root->Insert(1);

	do
	{
		system("CLS");
		std::cout << "\nTree DataStructure Problems" << std::endl;
		std::cout << "\n1) InOrder Traversal" << std::endl;
		std::cout << "\n2) Level Order Traversal" << std::endl;
		std::cout << "\n3) ReverseLevelOrderTraversal" << std::endl;
		std::cout << "\n4) Number Of Leaf Nodes" << std::endl;
		std::cout << "\n5) Print Nodes at KDistance from root" << std::endl;
		std::cout << "\n6) Height Of Binary Tree -- Iterative" << std::endl;
		std::cout << "\n7) Left view Of Binary Tree -- Recursion" << std::endl;
		std::cout << "\n8) Right view Of Binary Tree -- Recursion" << std::endl;
		std::cout << "\n9) Count Half Nodes in Binary Tree Iterative" << std::endl;
		std::cout << "\n10)Top view Of Binary Tree -- Iterative" << std::endl;
		std::cout << "\n11) Right view Of Binary Tree -- Iterative" << std::endl;
		std::cout << "\n12) Left view Of Binary Tree  -- Iterative" << std::endl;
		std::cout << "\n13) Size Of Binary Tree - Recursive" << std::endl;
		std::cout << "\n14) Spiral Travels Of Binary Tree" << std::endl;
		std::cout << "\n15) Vertical Travels Of Binary Tree" << std::endl;
		std::cout << "\n16) Print leftmost and rightmost nodes of a Binary Tree" << std::endl;
		std::cout << "\n17) Bottom view of a Binary Tree" << std::endl;
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
				std::cout << "\nLeft view of given binary tree -- Recursion\t" << std::endl;
				L_maxLevel = 0;
				TreeProblems::LeftViewOfTree(root, 1, &L_maxLevel);
				std::cout << std::endl;
				break;
			case 8:
				std::cout << "\nRight view of given binary tree -- Recursion\t" << std::endl;
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
				TreeProblems::TopViewOfTree(root);
				break;
			case 11:
				std::cout << "Right View of a given binary tree -- iteratively" << std::endl;
				TreeProblems::RightViewOfTreeIterative(root);
				break;
			case 12:
				std::cout << "Left View of a given binary tree -- iteratively" << std::endl;
				TreeProblems::LeftViewOfTreeIterative(root);
				break;
			case 13:
				std::cout << "Size a given binary tree -- Recursive" << std::endl;
				std::cout << "Size a given binary tree --> \t" << TreeProblems::SizeOfBinaryTree(root);
				break;
			case 14:
				std::cout << "Spiral traversal of given tree" << std::endl;
				TreeProblems::SpiralPrintOfTree(root);
				break;
			case 15:
				std::cout << "Spiral traversal of given tree" << std::endl;
				TreeProblems::VerticalOrderTraversal(root);
				break;
			case 16:
				std::cout << "Print LeftMost RightMost Node (CornerNodes) of Binary Tree" << std::endl;
				TreeProblems::PrintLeftMostRightMostNode(root);
				break;
			case 17:
				std::cout << "Bottom View of a given Binary Tree" << std::endl;
				TreeProblems::BottomViewOfBinaryTree(root);
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

		if ((iterator_node->getLeftNode() == nullptr) && (iterator_node->getRightNode() == nullptr))
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
	m_queue.push(nullptr);

	while (!m_queue.empty()) {
		TreeNode *iternator_node = m_queue.front();

		if (level == klevel && iternator_node != nullptr)
		{
			std::cout << "\t" << iternator_node->getNodeData();
		}
		m_queue.pop();
		if (iternator_node == nullptr)
		{
			if (m_queue.front()) {
				m_queue.push(nullptr);
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

	if (root == nullptr)
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

int TreeProblems::SizeOfBinaryTree(TreeNode *root)
{
	if (root == nullptr)
		return 0;
	else
		return ( SizeOfBinaryTree(root->getLeftNode()) + 1 + SizeOfBinaryTree(root->getRightNode()) );
}

void TreeProblems::TopViewOfTree(TreeNode *root)
{
	//std::map<int, int> m_unorderedMap;
	std::queue< std::pair<TreeNode *,int> >  m_Queue;
	std::unordered_map<int, long int> m_unorderedMap;
	std::unordered_map<int, long int>::iterator map_iterator;

	if (root == nullptr)
		return;

	m_Queue.push(std::make_pair(root,0));

	while (!m_Queue.empty())
	{
		std::pair<TreeNode *, int> iterator_pair = m_Queue.front();
		TreeNode *iterator_node = iterator_pair.first;
		int m_distance = iterator_pair.second;

		map_iterator = m_unorderedMap.find(m_distance);
		if (map_iterator == m_unorderedMap.end())
		{
			m_unorderedMap.insert(std::pair<int, long int>(m_distance, iterator_node->getNodeData()));
			std::cout << "\t" << iterator_node->getNodeData();
		}

		if (iterator_node->getLeftNode() != nullptr)
			m_Queue.push(std::make_pair(iterator_node->getLeftNode(), m_distance - 1));
			
		if (iterator_node->getRightNode() != nullptr)
			m_Queue.push(std::make_pair(iterator_node->getRightNode(), m_distance + 1));
	
		m_Queue.pop();
	}
}

void TreeProblems::RightViewOfTreeIterative(TreeNode *root)
{
	if (root == nullptr)
		return;

	std::queue<TreeNode *> m_queue;
	m_queue.push(root);

	while (!m_queue.empty())
	{
		int n = m_queue.size();

		for(int i=1;i<=n;i++){
			TreeNode *iterator_node = m_queue.front();
			m_queue.pop();

			if (i == n)
				std::cout << "\t" << iterator_node->getNodeData();

			if (iterator_node->getLeftNode() != nullptr)
				m_queue.push(iterator_node->getLeftNode());

			if (iterator_node->getRightNode() != nullptr)
				m_queue.push(iterator_node->getRightNode());
		}
	}
}

void TreeProblems::LeftViewOfTreeIterative(TreeNode *root)
{
	if (root == nullptr)
		return;

	std::queue<TreeNode *> m_queue;
	m_queue.push(root);

	while (!m_queue.empty())
	{
		int queueSize = m_queue.size();

		for (int i = 0; i < queueSize; i++)
		{
			TreeNode *iteratorNode = m_queue.front();
			m_queue.pop();

			if (i == 0)
				std::cout << "\t" << iteratorNode->getNodeData();

			if (iteratorNode->getLeftNode() != nullptr)
				m_queue.push(iteratorNode->getLeftNode());
			if (iteratorNode->getRightNode() != nullptr)
				m_queue.push(iteratorNode->getRightNode());
		}
	}
}

void TreeProblems::SpiralPrintOfTree(TreeNode *root)
{
	if (root == nullptr)
		return;

	std::stack<TreeNode *> m_ltor;
	std::stack<TreeNode *> m_rtol;

	m_ltor.push(root);

	while(!m_ltor.empty() || !m_rtol.empty())
	{
		while(!m_ltor.empty())
		{
			TreeNode *iterator_node = m_ltor.top();
			std::cout << "\t" << iterator_node->getNodeData();
			if(iterator_node->getLeftNode() != nullptr)
				m_rtol.push(iterator_node->getLeftNode());
			if(iterator_node->getRightNode() != nullptr)
				m_rtol.push(iterator_node->getRightNode());

			m_ltor.pop();
		}

		if(!m_rtol.empty())
		{
			TreeNode *iterator_node = m_rtol.top();
			std::cout << "\t" << iterator_node->getNodeData();
			if(iterator_node->getRightNode() != nullptr)
				m_ltor.push(iterator_node->getRightNode());
			if(iterator_node->getLeftNode() != nullptr)
				m_ltor.push(iterator_node->getLeftNode());

			m_rtol.pop();
		}
	}
}



void findMinMaxHD(TreeNode* m_currentNode,int *m_min, int *m_max, int hd) 
{
	if (m_currentNode == nullptr)
		return;

	if (hd < *m_min)
		*m_min = hd;
	else if (hd > *m_max)
		*m_max = hd;

	findMinMaxHD(m_currentNode->getLeftNode(), m_min, m_max, hd - 1);
	findMinMaxHD(m_currentNode->getRightNode(), m_min, m_max, hd + 1);

}

void printVerticalLines(TreeNode *m_currentNode, int m_lineNo, int hd)
{
	if (m_currentNode == nullptr)
		return;

	if (hd == m_lineNo)
		std::cout << "\t" << m_currentNode->getNodeData();

	printVerticalLines(m_currentNode->getLeftNode(), m_lineNo, hd - 1);
	printVerticalLines(m_currentNode->getRightNode(), m_lineNo, hd + 1);
}

void TreeProblems::VerticalOrderTraversal(TreeNode *root)
{
	int m_min = 0, m_max = 0;
	findMinMaxHD(root,&m_min, &m_max, 0);

	for (int lineNo = m_min; lineNo <= m_max; lineNo++)
	{
		std::cout << "\nNodes, Vertical Line of Tree --  " << lineNo << ",   Nodes  Present -- ";
		printVerticalLines(root, lineNo, 0);
	}
	std::cout << std::endl;
}


void TreeProblems::PrintLeftMostRightMostNode(TreeNode *root)
{
	if (root == nullptr)
		return;

	std::queue<TreeNode *> m_queue;
	
	bool isFirst = false;
	bool isOne = false;
	int last;

	m_queue.push(root);
	m_queue.push(nullptr);

	while (!m_queue.empty())
	{
		TreeNode *iterator_node = m_queue.front();
		m_queue.pop();

		if (isFirst)
		{
			std::cout << "\t" << iterator_node->getNodeData();

			if (iterator_node->getLeftNode() != nullptr)
				m_queue.push(iterator_node->getLeftNode());
			if (iterator_node->getRightNode() != nullptr)
				m_queue.push(iterator_node->getRightNode());

			isFirst = false;
			isOne = true;
		}
		else if (iterator_node == nullptr)
		{
			if (m_queue.size() >= 1)
				m_queue.push(nullptr);

			isFirst = true;

			if (!isOne)
				std::cout << "\t" << last;
		}
		else
		{
			last = iterator_node->getNodeData();
			isOne = false;

			if (iterator_node->getLeftNode() != nullptr)
				m_queue.push(iterator_node->getLeftNode());
			if (iterator_node->getRightNode() != nullptr)
				m_queue.push(iterator_node->getRightNode());
		}
	}
}

void TreeProblems::BottomViewOfBinaryTree(TreeNode *root)
{
	if (root == nullptr)
		return;

	std::map<int, long int> m_map;
	std::map<int, long int>::iterator mapIterator;
	std::queue<std::pair<TreeNode *,int> > m_queue;

	m_queue.push(std::make_pair(root,0));

	while (!m_queue.empty())
	{
		std::pair<TreeNode *, int> iteratorNode = m_queue.front();
		int nodeValue = iteratorNode.first->getNodeData();
		int HD = iteratorNode.second;

		mapIterator= m_map.find(HD);
		if (mapIterator == m_map.end())
			m_map.insert(std::pair<int, long int>(HD, nodeValue));
		else
			(*mapIterator).second = (long)nodeValue;

		if (iteratorNode.first->getLeftNode() != nullptr)
			m_queue.push(std::make_pair(iteratorNode.first->getLeftNode(), HD - 1));

		if(iteratorNode.first->getRightNode() != nullptr)
			m_queue.push(std::make_pair(iteratorNode.first->getRightNode(), HD + 1));

		m_queue.pop();
	}

	for (auto& mapvalue : m_map) {
		std::cout << "\t" << mapvalue.second;
	}

}