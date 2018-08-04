#include <iostream>
#include <stdlib.h>
#include "../header/LLNode.h"

 LLNode::LLNode(int data)
	: m_data(data), m_next(nullptr)
{

}
void LLNode::Insert(int data)
{
	if (this->GetNextNode() == nullptr)
	{
		LLNode *new_node = new LLNode(data);
		this->SetNextNode(new_node);
	}
	else
	{
		this->GetNextNode()->Insert(data);
	}
}

void LLNode::SetNextNode(LLNode *new_node)
{
	this->m_next = new_node;
}

LLNode* LLNode::GetNextNode()
{
	return m_next;
}

int LLNode::GetNodeData()
{
	return this->m_data;
}

void LLNode::TraverseLL(LLNode *head)
{
	if (head == nullptr)
		return;
	else
	{
		while (head != nullptr)
		{
			std::cout << "\t" << head->GetNodeData();
			head = head->GetNextNode();
		}
	}
}

