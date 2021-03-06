#pragma once
#ifndef  HEADER_ARRAYPROBLEMS_H
#define HEADER_ARRAYPROBLEMS_H

namespace ArrayProblems
{
	void printRepeatatingNumbers(int array[], int size);
	void NextGreaterElementInGivenArray(int m_input[], int size);
	void ProblemsMenu();
	void FindPivotInSortedArrayBruteForce(int m_input[], int size);
	void MaxmimSubArrayKadanesAlgorithm(int m_input[], int size);
	void FindPivotInSortedArrayWithBinarySearch(int m_input[], int size);
	void FindMissingNumberInArray(int m_input[], int m_size);
	void FindMissingNumberInArrayXORMethod(int m_input[], int m_size);
	void WaterTrappingInBetweenBuilding(int m_input[], int m_size);
	void LonelyInteger(int m_input[], int m_size);
	//void FindElementInRotatedSortedArrayWithBinarySearch(int m_input[], int size,int key);
	//void FindElementInRotatedSortedArrayWithLinearSearch(int m_input[], int size,int key);
}

#endif // ! HEADER_ARRAYPROBLEMS_H
