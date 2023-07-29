#include <iostream>
#include <fstream>

int main()
{
	std::ifstream flie_read("in.txt");
	if (!flie_read.is_open())
	{
		std::cout << "File 'in.txt' not open!\n";
		return 0;
	}

	// Первый массив
	int* arr_one = nullptr;

	// Получаем размер первого массива
	int size_arr_one;
	flie_read >> size_arr_one;

	if (size_arr_one > 0)
	{
		arr_one = new int[size_arr_one];

		int numb_first; // Записываем отдельно первый элемент массива
		flie_read >> numb_first;
		for (int i = 0; i < size_arr_one - 1; i++)
		{
			flie_read >> arr_one[i];
		}
		arr_one[size_arr_one - 1] = numb_first; // Зпаисываем в конец первый элемент

	}



	// Второй массив
	int* arr_two = nullptr;

	// Получаем размер второго массива
	int size_arr_two;
	flie_read >> size_arr_two;

	if (size_arr_two > 0)
	{
		arr_two = new int[size_arr_two];


		for (int i = 1; i < size_arr_two; i++)
		{
			flie_read >> arr_two[i];
		}
		flie_read >> arr_two[0]; // Зпаисываем в начало последний элемент

	}
	flie_read.close();


	if (size_arr_two > 0 && size_arr_one > 0)
	{
		std::fstream flie_write("out.txt");
		if (!flie_write.is_open())
		{
			std::cout << "File 'out.txt' not open!\n";
			delete[] arr_one;
			delete[] arr_two;
			return 0;
		}

		flie_write << size_arr_two << std::endl;
		for (size_t i = 0; i < size_arr_two; i++)
		{
			flie_write << arr_two[i] << " ";
		}
		flie_write << std::endl;

		flie_write << size_arr_one << std::endl;
		for (size_t i = 0; i < size_arr_one; i++)
		{
			flie_write << arr_one[i] << " ";
		}


		flie_write.close();
	}


	delete[] arr_one;
	delete[] arr_two;

	return 0;

}
