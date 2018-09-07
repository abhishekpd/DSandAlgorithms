#pragma once

#ifndef  HEADER_MATRIXPROBLEMS_H
#define HEADER_MATRIXPROBLEMS_H
#include <vector>

namespace MatrixProblems {

	void MatrixProblemsMenu();
	void Multiplication(int *arrayMatrix, std::vector< std::vector<int> > vectorMatrix, int m_row, int m_colun);
	void SumOfNeighbouringElements(int **matrix);
}
#endif