#pragma once
#ifndef HEADER_TREEPROBLES_H
#define HEADER_TREEPROBLEMS_H

#include "TreeNode.h"

namespace TreeProblems
{
	void TreeOperationsMenu();
	void printKDistanceNode(TreeNode *root, int level);
	void LevelOrderTraversal(TreeNode *root);
	void ReverseLevelOrderTraversal(TreeNode *root);
	int NumberOfLeafNodesInTree(TreeNode *root);
	int HeightOfBinaryTreeIterative(TreeNode *root);
	TreeNode* LowestCommonAncestor(TreeNode *root,int NodeA,int NodeB);
	void LeftViewOfTree(TreeNode *root, int curren_level, int *max_level);
	void RightViewOfTree(TreeNode *root, int curren_level, int *max_level);
	int CountHalfNodesInATree(TreeNode *root);
	void TopViewOfTree(TreeNode *root);
	void RightViewOfTreeIterative(TreeNode *root);
	void LeftViewOfTreeIterative(TreeNode *root);
	int SizeOfBinaryTree(TreeNode *root);
}

#endif // ! HEADER_TREEPROBLEMS_H