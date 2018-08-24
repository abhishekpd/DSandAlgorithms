#include "../header/MatrixProblems.h"
#include <iostream>


void MatrixProblems::Multiplication(int ** arrayMatrix, std::vector< std::vector<int> > vectorMatrix,int m_rows, int m_column)
{
	int m_VColumns,m_VRows;
	m_VColumns = vectorMatrix.at(0).size();
	m_VRows = vectorMatrix.size();

	

	// m_rows x m_column (matrix with m row and n columns
	// m_VRows x m_VColumns (matrix with  n rows and o colums

	// Multiplication possible if and only if m_column == m_VRows (columns of A matrix equal to row of B matrix 
	// resultant matrix m_rows x m_VColumns  (Rows of A matrix x  column of B matrix)
	if (m_column != m_VRows)
	{
		std::cout << "\Matrix Multplication not possible" << std::endl;
	}
	else if (m_column == m_VRows)
	{
		//int resultMatrix[m_rows][m_VColumns];
		//int *resultMatrix = (int *)malloc(sizeof(int)* m_rows*m_VColumns);
		int **resultMatrix = new int*[m_rows];
		for (int i = 0; i < m_rows; i++)
			resultMatrix[i] = new int[m_column];

			for (int row = 0; row < m_rows; row++)
			{
				for (int column = 0; column < m_VColumns; column++)
				{
					resultMatrix[row][column] = 0;
					for (int commonvalue = 0; commonvalue < m_column; commonvalue++)
					{
						resultMatrix[row][column] += arrayMatrix[row][commonvalue] * vectorMatrix.at(commonvalue).at();
					}
				}

			}


	}
}

