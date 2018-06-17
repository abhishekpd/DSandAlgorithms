#pragma once
#ifndef HEADER_LLNODE_H
#define HEADER_LLNODE_H

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
#endif // ! HEADER_LLNODE_H

