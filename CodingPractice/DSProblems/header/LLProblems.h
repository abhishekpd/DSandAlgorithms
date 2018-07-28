#pragma once

#ifndef  HEADER_LLPROBLEMS_H
#define HEADER_LLPROBLEMS_H

#include "../header/LLNode.h"

namespace LLProblems {
	void LLProblemsMenu();
	LLNode* ReverseLLWithOutRecursion(LLNode *head);
	bool DetectLoopInLL(LLNode *head);
	int NNodeFromEndOfLL(LLNode *head,int loc);
}


#endif // ! HEADER_LLPROBLEMS_H

