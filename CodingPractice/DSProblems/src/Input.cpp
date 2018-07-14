#include "../header/Input.h"

int Input::GetArrayInput(int **mInput)
{
	int m_size, inp;
	std::cout << "Please enter no of input elements\t";
	std::cin >> m_size;
	*mInput = (int *)malloc((sizeof(int))*m_size);

	for (int i = 0; i < m_size; i++) {
		std::cin >> inp;
		*(*(mInput)+i) = inp;
	}
	return m_size;
}