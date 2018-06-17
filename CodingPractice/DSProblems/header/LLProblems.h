#pragma once

#ifndef  HEADER_LLPROBLEMS_H
#define HEADER_LLPROBLEMS_H

#include "../header/LLNode.h"

namespace LLProblems {
	void LLProblemsMenu();
	LLNode* ReverseLLWithOutRecursion(LLNode *head);
	bool DetectLoopInLL(LLNode *head);
}


#endif // ! HEADER_LLPROBLEMS_H

