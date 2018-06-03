#include "../header/ArrayProblems.h"

void printRepeatatingNumbers(int array[], int size)
{
	int i = 0;
	std::cout << "\nRepeatating numbers in Array are\n";
	for (i = 0; i < size; i++)
	{
		if (array[abs(array[i])] >= 0) // check value of array index,if positive then make it negative 
		{
			array[abs(array[i])] = -array[abs(array[i])];
		}
		else if (array[abs(array[i])] < 0) // check value of array index,if negative then we have already encountered value and it's repetating
		{
			std::cout << "\t" << abs(array[i]);
		}
	}
}