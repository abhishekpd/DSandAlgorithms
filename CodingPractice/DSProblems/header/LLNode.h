#pragma once
#ifndef LLNODE_H
#define LLNODE_H

class LLNode
{
private:
	int m_data;
	LLNode *m_next;

public:
	LLNode(int data);
	int GetNodeData();
	void Insert(int data);
	void SetNextNode(LLNode *next);
	LLNode* GetNextNode();
	static void TraverseLL(LLNode *head);
};
#endif // LLNODE_H

