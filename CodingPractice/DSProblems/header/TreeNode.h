#pragma once

#include <iostream>

#ifndef HEADER_TREENODE_H
#define HEADER_TREENODE_H

class TreeNode
{
private:
	int m_data;
	TreeNode* m_left;
	TreeNode* m_right;

public:
	TreeNode(int data);
	TreeNode* getLeftNode();
	TreeNode* getRightNode();
	void setLeftNode(TreeNode *left);
	void setRightNode(TreeNode *right);
	int getNodeData();

	void InOrder(TreeNode *root);
	void Insert(int data);
};



#endif // ! HEADER_TREENODE_H
