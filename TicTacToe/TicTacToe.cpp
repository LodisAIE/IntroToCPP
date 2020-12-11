#include <iostream>

void printArray(int arr[], int length)
{
	for (int i = 0; i < length; i++)
		std::cout << arr[i] << std::endl;

	system("pause");
}

int main()
{
	int numbers[] = { 1,2,3,4,5};
	printArray(numbers, 5);
}