#pragma once
#ifndef TREEPROBLES_H
#define TREEPROBLEMS_H

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
	//void TopViewOfTree(TreeNode *root);
}

#endif // ! TREEPROBLEMS_H