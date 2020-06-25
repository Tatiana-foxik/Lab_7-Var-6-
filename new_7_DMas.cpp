#include <iostream>
#include <fstream>

using namespace std;

#define n 5

void input_matr(int a[n][n])		//Функция записи массива с клавиатуры
{
	cout << "Введите элементы массива\n";
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			cout << "элемент[" << i << "," << j << "]: ";
			cin >> a[i][j];
		}
	}
}

void input_file(int a[n][n])		//Функция записи массива из файла
{
	ifstream f("matrix.txt");
	if (f.is_open())
	{
		cout << "Файл открыт\n";
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < n; j++)
			{
				f >> a[i][j];
			}
		}
	}
	else
	{
		cout << "Ошибка открытия файла\n";
	}
	f.close();
}

int main()
{
	setlocale(LC_ALL, "Russian");
	cout << "Курносова Татьяна Пи-192\n";
	int t;
	int a[n][n];
	void (*mas)(int[n][n]);
	mas = NULL;
	cout << "Вы хотите взять заполненный масиив(1) или же заполнить его самостоятельно(0)\n";
	cin >> t;
	if (t == 1)
	{
		mas = input_matr;
	}
	else
	{
		mas = input_file;
	}
}