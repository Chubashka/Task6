#include <iostream>

using namespace std;

string Checking_arr1(int** arr, int rows, int cols);

int main()
{
	setlocale(LC_ALL, "Russian");
	srand(time(0));
	int cols, rows, check;
	char c;
	do
	{
		system("cls");
		cout << "Введите количество строк: ";
		cin >> rows;
		cout << "Введите количество столбцов: ";
		cin >> cols;
		int** arr = new int* [rows];
		for (int i = 0; i < rows; i++)
		{
			arr[i] = new int[cols];
		}
		for (int i = 0; i < rows; i++)
		{
			for (int j = 0; j < cols; j++)
			{
				arr[i][j] = rand() % (5 - 1 + 1) + 1;
			}
		}
		for (int i = 0; i < rows; i++)
		{
			for (int j = 0; j < cols; j++)
			{
				cout << arr[i][j] << "\t";
			}
			cout << endl;
		}
		cout << Checking_arr1(arr, rows, cols);
		for (int i = 0; i < rows; i++)
			delete[] arr[i];
		delete[] arr;
		cout << "Хотите еще раз запустить программу? (y-да)";
		cin >> c;
	} while (c == 'y');
	system("PAUSE");
}

string Checking_arr1(int** arr, int rows, int cols)
{
	string str;
	int k2 = 0;
	int k = 0;
	int k1 = 0;
	int j = 0;
	int cout = 0;
	bool f = true;
	bool f1 = true;
	for (int j = 0; j < cols; j++)
	{
		bool flag = true;
		if (j % 2 == 0)
		{
			for (int i = rows - 1; i; i--)
			{
				if (arr[i][j] >= arr[i - 1][j])
				{

					flag = false;
					break;
				}
			}
			if (flag)
				k++;
		}
	}
	for (int j = 0; j < cols; j++)
	{
		bool flag = true;
		if (j % 2 != 0)
		{
			for (int i = 0; i < rows - 1; i++)
			{
				if (arr[i][j] >= arr[i + 1][j])
				{

					flag = false;
					break;
				}
			}
			if (flag)
				k++;
		}
	}
	if (k == cols)
		++cout;
	for (j = 0; j < cols; j++)
	{
		if (arr[0][j] < arr[0][j+1])
		{
			++k1;
		}
		j++;
	}
	int k4 = 0;
	if (cols % 2 == 0)
	{
		if (k1 == cols / 2)
			k4++;
	}
	if (cols % 2 != 0)
	{
		if (k1 == cols / 2)
			k4++;
	}
	for (j = 1; j < cols; j++)
	{
		if (arr[rows - 1][j] < arr[rows - 1][j + 1])
		{
			++k2;
		}
		j++;
	}
		int k5 = 0;
		if ((cols-1) % 2 == 0)
		{
			if (k2 == (cols-1) / 2)
				k5++;
		}
		if ((cols-1) % 2 != 0)
		{
			if (k2 == (cols-1) / 2)
				k5++;
		}
		if (cout == 1 && k4 == 1 && k5 == 1)
			str = { "Элементы массива образуют упорядоченность по типу a)" };
		else 
			str = { "Элементы массива не образуют упорядоченность по типу a)" };

	return str;
}
