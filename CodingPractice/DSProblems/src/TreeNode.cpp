#include "../header/TreeNode.h"

TreeNode::TreeNode(int data)
	: m_data(data), m_left(nullptr), m_right(nullptr)
{
}

int TreeNode::getNodeData()
{
	return (m_data);
}

TreeNode* TreeNode::getLeftNode()
{
	return m_left;

}

TreeNode* TreeNode::getRightNode()
{
	return m_right;
}

void TreeNode::setLeftNode(TreeNode *left)
{
	this->m_left = left;
}

void TreeNode::setRightNode(TreeNode *right)
{
	this->m_right = right;
}

void TreeNode::InOrder(TreeNode *root)
{

	if (root == nullptr)
		return;
	InOrder(root->getLeftNode());
	std::cout << "\t" << root->m_data;
	InOrder(root->getRightNode());

}

void TreeNode::Insert(int data)
{
	if (this->m_data >= data)
	{
		if (this->getLeftNode() == nullptr)
		{
			TreeNode *new_node = new TreeNode(data);
			this->setLeftNode(new_node);
		}
		else if (this->getLeftNode() != nullptr)
		{
			this->getLeftNode()->Insert(data);
		}		
	}
	else if (this->m_data < data)
	{
		if(this->getRightNode() == nullptr)
		{
			TreeNode *new_node = new TreeNode(data);
			this->setRightNode(new_node);
		}
		else if (this->getRightNode() != nullptr)
		{
			this->getRightNode()->Insert(data);
		}
	}
}
