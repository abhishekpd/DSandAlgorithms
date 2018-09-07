#include "../header/MatrixProblems.h"
#include <iostream>
#include <stack>
#include <memory>

void MatrixProblems::MatrixProblemsMenu()
{
	int m_choice;
	do
	{
		system("CLS || clear");
		std::cout << "\nMatrix Problems" << std::endl;
		std::cout << "\n1) Matrix Multiplication" << std::endl;
		std::cout << "\n2) Sum of Neighbouring elements in matrix" << std::endl;
		//std::cout << "\n3) Detect Loop in LL" << std::endl;
		//std::cout << "\n4) Print node at N position from end in reverse direction" << std::endl;
		std::cout << "\nInput your choice\t";
		std::cin >> m_choice;

		switch (m_choice)
		{
			case 1:
			{
				int AMatrix[2][2] 	= 	{{ 1, 2 },
										{ 4, 6}
										};
				//std::vector<std::vector<int> > BVectorMatrix;
				std::vector<std::vector<int> > BVectorMatrix(3, std::vector<int>(2, 3));


				//BVectorMatrix.at(0).push_back(3);
				//BVectorMatrix.at(0).push_back(6);
				//BVectorMatrix.at(1).push_back(9);
				//BVectorMatrix.at(1).push_back(8);
				
				MatrixProblems::Multiplication((int *)AMatrix,BVectorMatrix,2,2);
			}
			break;
			case 2:
			{
				std::cout << "Coming ....." << std::endl;
				int** a2dArray = new int*[5];	

				for(int i=0;i<5;i++)
					a2dArray[i] = new int[5];


				

				std::cout << "\n" <<  a2dArray[4][3] << std::endl;
				for(int i=0;i<5;i++){
					for(int j=0;j<5;j++){
						a2dArray[i][j] = 8;	
					}
				}
						
				
				MatrixProblems::SumOfNeighbouringElements(a2dArray);
			}
			break;
		}
		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		std::cin.get();
	}while(m_choice != 99);
	
}



void MatrixProblems::Multiplication(int *arrayMatrix, std::vector< std::vector<int> > vectorMatrix,int m_rows, int m_column)
{
	int m_VColumns,m_VRows;
	m_VColumns = vectorMatrix.at(0).size();
	m_VRows = vectorMatrix.size();

	std::cout << "1st Matrix\t" << m_rows << "\t" << m_column << std::endl;
	 for (int i = 0; i < m_rows; i++)
	 {
		for (int j = 0; j < m_column; j++)
			std::cout << *((arrayMatrix+i*m_column) + j) << " ";

        	//printf("%d ", *((arrayMatrix+i*m_column) + j));
		std::cout << std::endl;
	 }
      

	std::cout << "2st Matrix\t" << m_VRows << "\t" << m_VColumns << std::endl;
	for (int i = 0; i < m_VRows; i++)
	 {
		for (int j = 0; j < m_VColumns; j++)
        	printf("%d ", vectorMatrix.at(i).at(j));

		std::cout << std::endl;
	 }


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
					resultMatrix[row][column] += *((arrayMatrix+ row*m_column)+commonvalue) * vectorMatrix.at(commonvalue).at(column);
				}
			}

		}
		std::cout << "\nResultant matrix is as  " << m_rows  << " " << m_VColumns << std::endl;
		for (int i = 0; i < m_VRows; i++)
	 	{
			for (int j = 0; j < m_VColumns; j++)
        		std::cout << resultMatrix[i][j] << " ";

			std::cout << std::endl;
	 	}

	}
}




void MatrixProblems::SumOfNeighbouringElements(int **matrix)
{
	for (int i = 0; i < 5; i++)
	{
		for (int j = 0; j < 5; j++)
			std::cout << matrix[i][j] << " ";

		std::cout << std::endl;
	}

}


