#pragma once

#ifndef  HEADER_SORTINGSEARCHINGALGORITHM_H
#define HEADER_SORTINGSEARCHINGALORITHM_H

namespace SortingSearchingAlgorithms
{
	void SortingSearchingMenu();
	void MergeSort(int m_input[],int m_leftindex, int m_rightIndex);
	void PrintArray(int m_input[], int size);
	void MergeRoutine(int m_input[], int m_leftindex,int m_midIndex,int m_rightIndex);
	void Quicksort(int m_input[], int m_startIndex, int m_endIndex);
	int PartitionQuickSort(int m_input[], int m_startIndex, int endIndex);
};

#endif // ! HEADER_SORTINGSEARCHINGALGORITHM_H

