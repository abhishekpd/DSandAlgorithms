#pragma once
#ifndef TREEPROBLES_H
#define TREEPROBLEMS_H

#include "TreeNode.h"

void TreeOperationsMenu();
void printKDistanceNode(TreeNode *root, int level);
void LevelOrderTraversal(TreeNode *root);
void ReverseLevelOrderTraversal(TreeNode *root);
int NumberOfLeafNodesInTree(TreeNode *root);
int HeightOfBinaryTreeIterative(TreeNode *root);

#endif // ! TREEPROBLEMS_H