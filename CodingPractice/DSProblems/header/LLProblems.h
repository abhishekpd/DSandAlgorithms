#pragma once

#ifndef  LLPROBLEMS_H
#define LLPROBLEMS_H

#include "../header/LLNode.h"

namespace LLProblems {
	void LLProblemsMenu();
	LLNode* ReverseLLWithOutRecursion(LLNode *head);
	bool DetectLoopInLL(LLNode *head);
}


#endif // ! LLPROBLEMS_H

