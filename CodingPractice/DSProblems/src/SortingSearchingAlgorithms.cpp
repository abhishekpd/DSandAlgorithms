#include "../header/SortingSearchingAlgorithms.h"
#include <iostream>
#include <string>
#include <stdlib.h>


void SortingSearchingAlgorithms::SortingSearchingMenu()
{
	system("CLS");
	int m_choice;
	do
	{
			system("CLS");
			std::cout << "\nSearching and Sorting Problems" << std::endl;
			std::cout << "\n1) Bubble Sort" << std::endl;
			std::cout << "\n2) Insertion Sort" << std::endl;
			std::cout << "\n3) Merge Sort" << std::endl;
			std::cout << "\n4) Quick Sort" << std::endl;
			std::cout << "\n5) Print Nodes at KDistance from root" << std::endl;
			std::cout << "\nInput your choice\t";
			std::cin >> m_choice;
			switch (m_choice)
			{
			case 1:
				std::cout << "\nComing Soon" << std::endl;
				//root->InOrder(root);
				std::cout << std::endl;
				break;
			case 2:
				std::cout << "\nComing Soon" << std::endl;
				//TreeProblems::LevelOrderTraversal(root);
				std::cout << std::endl;
				break;
			case 3:
				{
					std::cout << "\nMerge Sort" << std::endl;
					int m_inputArr[] = { 73,85,94,21,27,34,47,54,66 };
					std::cout << "Input Aray --->>> ";
					SortingSearchingAlgorithms::PrintArray(m_inputArr, (sizeof(m_inputArr) / sizeof(int)));
					SortingSearchingAlgorithms::MergeSort(m_inputArr, 0, (sizeof(m_inputArr) / sizeof(int) - 1));
					std::cout << "\nResult --->>> ";
					SortingSearchingAlgorithms::PrintArray(m_inputArr, (sizeof(m_inputArr) / sizeof(int)) );
					std::cin.get();
					std::cout << std::endl;
				}
				break;
			case 4:
				{	
					std::cout << "\nQuick Sort" << std::endl;;
					int m_inputArr[] = { 73,85,94,21,27,34,47,54,66 };
					std::cout << "Input Aray --->>> ";
					SortingSearchingAlgorithms::PrintArray(m_inputArr, (sizeof(m_inputArr) / sizeof(int)));
					SortingSearchingAlgorithms::Quicksort(m_inputArr, 0, (sizeof(m_inputArr) / sizeof(int) - 1));
					std::cout << "\nResult --->>> ";
					SortingSearchingAlgorithms::PrintArray(m_inputArr, (sizeof(m_inputArr) / sizeof(int)));
					std::cin.get();
					std::cout << std::endl;
				}
				break;
			case 5:
				std::cout << "\nPlease enter kDistance from root\t";
			//	std::cin >> m_input;
				std::cout << std::endl;
				break;
			}
	} while (m_choice != 99);
}


void SortingSearchingAlgorithms::Quicksort(int m_input[], int m_startIndex, int m_endIndex)
{
	if (m_startIndex < m_endIndex) {
		int m_pivotIndex = SortingSearchingAlgorithms::PartitionQuickSort(m_input, m_startIndex, m_endIndex);
		SortingSearchingAlgorithms::Quicksort(m_input, m_startIndex, m_pivotIndex - 1);
		SortingSearchingAlgorithms::Quicksort(m_input, m_pivotIndex + 1,m_endIndex);
	}
}


int SortingSearchingAlgorithms::PartitionQuickSort(int m_input[], int m_startIndex, int m_endIndex) 
{
	int m_pivot = m_input[m_endIndex];
	int m_pIndex = m_startIndex;
	int temp;

	for (int i = m_startIndex; i < m_endIndex; i++) {
		if (m_input[i] <= m_pivot) {
			temp = m_input[i];
			m_input[i] = m_input[m_pIndex];
			m_input[m_pIndex] = temp;
			m_pIndex++;
		}
	}

	temp = m_input[m_endIndex];
	m_input[m_endIndex] = m_input[m_pIndex];
	m_input[m_pIndex] = temp;

	return m_pIndex;
}

void SortingSearchingAlgorithms::MergeSort(int m_input[],int m_leftindex,int m_rightIndex)
{
	if (m_leftindex < m_rightIndex) {
		int m_midIndex = (m_leftindex + m_rightIndex ) / 2;

		SortingSearchingAlgorithms::MergeSort(m_input, m_leftindex, m_midIndex);
		SortingSearchingAlgorithms::MergeSort(m_input, m_midIndex+1,m_rightIndex);

		SortingSearchingAlgorithms::MergeRoutine(m_input, m_leftindex, m_midIndex, m_rightIndex);
	}
}


void SortingSearchingAlgorithms::MergeRoutine(int m_input[], int m_leftindex, int m_midIndex, int m_rightIndex)
{
	int i, j, k;
	int m_leftHalfSize = m_midIndex - m_leftindex + 1;
	int m_RightHalfSize = m_rightIndex  - m_leftindex;

	int *m_LeftHalf, *m_RightHalf;

	m_LeftHalf = (int *)malloc((sizeof(int)) * m_leftHalfSize);
	m_RightHalf = (int *)malloc((sizeof(int)) * m_RightHalfSize);

	for (i = 0; i < m_leftHalfSize; i++) {
		*(m_LeftHalf + i )= m_input[m_leftindex + i];
	}

	for (j = 0; j < m_RightHalfSize; j++) {
		*(m_RightHalf + j) = m_input[m_midIndex + 1 + j];
	}

	i = j= 0;
	k = m_leftindex;

	while (i < m_leftHalfSize && j < m_RightHalfSize) {

		if (*(m_LeftHalf + i) <= *(m_RightHalf+j)) {
			m_input[k] = *(m_LeftHalf + i);
			i++;
			k++;
		}
		else {
			m_input[k] = *(m_RightHalf + j);
			j++;
			k++;
		}
	}

	while (i < m_leftHalfSize) {
		m_input[k] = *(m_LeftHalf + i);
		k++;
		i++;
	}

	while (j < m_RightHalfSize) {
		m_input[k] = *(m_RightHalf + j);
		k++;
		j++;
	}

	free(m_LeftHalf);
	free(m_RightHalf);
}


void SortingSearchingAlgorithms::PrintArray(int m_input[],int size) {
	for (int i = 0; i < size; i++)
	{
		std::cout << "\t" << m_input[i];
	}
}