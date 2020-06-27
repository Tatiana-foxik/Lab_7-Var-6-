﻿#include <iostream>
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

int* mas_x(int(*a)[n], int* x, int* x1,
	void (*mas)(int[n][n]))
{
	int pol, otr, l = 0;
	mas(a);
	for (int i = 0; i < n; i++)
	{
		pol = 0;
		otr = 0;
		for (int j = 0; j < n; j++)
		{
			if (a[i][j] >= 0)
			{
				pol += 1;
			}
			else
			{
				otr += 1;
			}
		}
		if (pol > otr)
		{
			x[l] = 1;
			l++;
		}
		else
		{
			x[l] = -1;
			l++;
		}
	}
	l = 0;
	for (int i = 0; i < n; i++)
	{
		x1[i] = a[0][i];
	}
	return x;
	return x1;
}

void proverka(int x[])
{
	for (int l = 0; l < n; l++)
	{
		cout << "x[" << l << "]: " << x[l] << " \n";
	}
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
	mas_x(a, x, mas);
	proverka(x);
}