#include <iostream>

void FizzBuzz(int num)
{
	for (int i = 0; i <= num; i++)
	{
		if (i % 3 == false && i % 5 == false)
		{
			std::cout << i << ": FizzBuzz" << std::endl;
		}
		else if (i % 5 == false)
		{
			std::cout << i << ": Buzz" << std::endl;
		}
		else if (i % 3 == false)
		{
			std::cout << i << ": Fizz" << std::endl;
		}
	}
}

int main()
{
	//This is the same as "Console.Write();"
	int num = 0;

	std::cout << "Please type a number: ";
	std::cin >> num;

	FizzBuzz(num);
	

	system("pause");
	return 1;
}