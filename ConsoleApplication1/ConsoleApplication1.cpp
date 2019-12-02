#include "stdafx.h"
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <ctime>
#include <iomanip>
using namespace std;

void MENU();//функція меню

//---------------Функції для знаходження оберненої матриці---------------
void Fill_Random_Inverse_Matrix(double **, int);//функція заповнення рандомної матриці
void Fill_Your_Inverse_Matrix(double **, int);//функція заповнення матриці з клавіатури
void Choose_Given_Inverse_Matrix(double **, int);//функція для вибору певної матриці, яка була вже дана
void Print_Matrix(double **, int);//функція виводу матриці
void Delete_Row_Column(double **, int, double **, int, int);//функція викреслювання строки та свобця
double Determinant_Matrix(double **matr, int n);//функція знахоження детермінанту матриці
void Transpon_Matrix(double **matr, double **tMatr, int n);//функція транспонування матриці
void Free_Memory(double **matr, int n);//функція очищення пам'яті
void Random_Matrix();//функція обрахунку рандомної матриці
void Your_Matrix();//функція обрахунку для матриці з клавіатури
void Given_Matrix();//функція для обрахунку матриці, яка була дана
void Print_Given_Inverse_Matrix();//функція виводу заданих матриць для пошуку оберненої матриці

//---------------Функції для знаходження коренів СЛАР методом Зейделя ---------------
void Given_Zeidel();//функція розв'язання заданих СЛАР методом Зейделя
void Random_Zeidel();//функція розв'язання рандомних СЛАР методом Зейделя
void Your_Zeidel();//функція розв'язання введених з клавіатури СЛАР методом Зейделя
void Fill_Random_Zeidel_Matrix(double **matrA, double *matrB, int n);//функція заповнення рандомної матриці для методу Зейделя 
void Fill_Your_Zeidel_Matrix(double **matrA, double *matrB, int n);//функція заповнення матриці для методу Зейделя з клавіатури
void Choose_Given_Zeidel_Matrix(double **matrA, double *matrB, int n);//функція вибору заданої матриці для методу Зейделя
void Print_Zeidel_Matrix(double **matrA, double *matrB, int n);//функція виводу матриці для методу Зейделя
void Print_Given_Zeidel_Matrix();//функція виводу заданих матриць для методу Зейделя

int main()
{
	MENU();//виклик функції меню
}

void MENU()//функція меню
{
	system("color F0");//змінна кольору консолі на білий
	int key;//змінна вибору пункту меню
	while (true)
	{
		cout << "MENU: \n";
		cout << "1. Find inverse matrix.\n";
		cout << "2. Find the roots of the SLAE by the Seidel method.\n";//SLAE - system of linear algebraic equations
		cout << "3. Information about program and author.\n";
		cout << "4. Exit the program.\n";
		cout << "Enter menu item: ";
		cin >> key;
		system("cls");
		switch (key)
		{
		case 1:
			cout << "MENU -> Find inverse matrix:\n";
			cout << "1. Create random matrix.\n";
			cout << "2. Enter matrix elements from the keyboard.\n";
			cout << "3. Use already created matrix.\n";
			cout << "Enter menu item: ";
			cin >> key;
			system("cls");
			switch (key)
			{
			case 1:
				Random_Matrix();//виклик функції знаходження оберненої матриці до рандомної
				break;
			case 2:
				Your_Matrix();//виклик функції знаходження оберненої матриці до введеної з клавіатури
				break;
			case 3:
				Given_Matrix();//виклик функції знаходження оберненої матриці до заданої в умові
				break;
			}
			break;
		case 2:
			cout << "MENU -> Find the roots of the SLAE by the Seidel method:\n";
			cout << "1. Create random matrix.\n";
			cout << "2. Enter matrix elements from the keyboard.\n";
			cout << "3. Use already created matrix.\n";
			cout << "Enter menu item: ";
			cin >> key;
			system("cls");
			switch (key)
			{
			case 1:
				Random_Zeidel();//виклик функції знаходження коренів СЛАР рандомної матриці
				break;
			case 2:
				Your_Zeidel();//виклик функції знаходження коренів СЛАР матриці заданої з клавіатури
				break;
			case 3:
				Given_Zeidel();//виклик функції знаходження коренів СЛАР матриці заданої в умові
				break;
			}
			break;
		case 3:
			cout << "Program finds inverse matrix and roots of the SLAE by the Seidel method.\n";
			cout << "Program was made by Lutsenko Oleksandr IS-8119.\n\n";
			break;
		case 4:
			exit(0);//вийти з програми
		}
	}
}

//======================================
//===========ОБЕРНЕНА МАТРИЦЯ===========
//======================================
void Given_Matrix()
{
	int n;//змінна для вибору матриці
	double det;//змінна для знаходження детермінанту
	cout << "MENU -> Find inverse matrix -> Use already created matrix:\n";
	Print_Given_Inverse_Matrix();//вивести задані матриці
	cout << "Choose matrix: ";
	cin >> n;//вибрати матрицю
	if (n <= 1)//якщо розмір матриці менше або дорівнює 1
	{
		cout << "Impossible to find inverse matrix.\n";
	}
	else//якщо розмір матриці більше 1
	{
		cout << endl;
		double **matr = new double *[n];//ініціалізувати розмір матриці
		double **inver_matr = new double *[n];//ініціалізувати розмір оберненої матриці
		double **trans_matr = new double *[n];//ініціалізувати розмір транспонованої матриці
		for (int i = 0; i < n; i++)
		{
			matr[i] = new double[n];//ініціалізувати розмір матриці
			inver_matr[i] = new double[n];//ініціалізувати розмір оберненої матриці
			trans_matr[i] = new double[n];//ініціалізувати розмір транспонованої матриці
		}
		Choose_Given_Inverse_Matrix(matr, n);//вибрати матрицю
		Print_Matrix(matr, n);//вивести матрицю
		det = Determinant_Matrix(matr, n);//знайти детермінант матриці
		cout << "\nMatrix determinant = " << det << endl << endl;//вивести детермінант матриці
		if (det != 0)//якщо детермінант не дорівнює 0
		{
			for (int i = 0; i < n; i++)//доки є рядки в матриці
			{
				for (int j = 0; j < n; j++)//доки в рядку матриці є елементи
				{
					int m = n - 1;//змінна для знаходження детермінанту та видалення рядка з стовбцем
					double **temp_matr = new double *[m];//ініціалізувати змінну для знаходження детермінанту та видалення рядка з стовбцем
					for (int k = 0; k < m; k++)//доки є рядки в новій матриці
					{
						temp_matr[k] = new double[m];//ініціалізувати змінну для знаходження детермінанту та видалення рядка з стовбцем
					}
					Delete_Row_Column(matr, n, temp_matr, i, j);//видалити рядок та стовбець з матриці
					inver_matr[i][j] = pow(-1.0, i + j + 2) * Determinant_Matrix(temp_matr, m) / det;//знайти елемент оберненої матриці
					Free_Memory(temp_matr, m);//очистити пам'ять
				}
			}
		}
		else//якщо детермінант дорівнює 0
		{
			cout << "Matrix determinant = 0, so this matrix is degenerate and does not have inverse matrix" << endl;
		}
		Transpon_Matrix(inver_matr, trans_matr, n);//транспонувати матрицю
		cout << "\n\t\t\tInverse \n\n";
		Print_Matrix(trans_matr, n);//вивести обернену матрицю
		cout << endl << endl;
		Free_Memory(trans_matr, n);//очистити пам'ять
		Free_Memory(matr, n);//очистити пам'ять
		Free_Memory(inver_matr, n);//очистити пам'ять
	}
}

void Your_Matrix()
{
	int n;//змінна для вибору матриці
	double det;//змінна для знаходження детермінанту
	cout << "MENU -> Find inverse matrix -> Enter matrix elements from the keyboard:\n";
	cout << "Enter matrix size: ";
	cin >> n;//задати розмір матриці
	if (n <= 1)//якщо розмір матриці менше або дорівнює 1
	{
		cout << "Impossible to find inverse matrix.\n";
	}
	else//якщо розмір матриці більше 1
	{
		cout << endl;
		double **matr = new double *[n];//ініціалізувати розмір матриці
		double **inver_matr = new double *[n];//ініціалізувати розмір оберненої матриці
		double **trans_matr = new double *[n];//ініціалізувати розмір транспонованої матриці
		for (int i = 0; i < n; i++)
		{
			matr[i] = new double[n];//ініціалізувати розмір матриці
			inver_matr[i] = new double[n];//ініціалізувати розмір оберненої матриці
			trans_matr[i] = new double[n];//ініціалізувати розмір транспонованої матриці
		}
		Fill_Your_Inverse_Matrix(matr, n);//заповнити матрицю елементами з клавіатури
		Print_Matrix(matr, n);//вивести матрицю
		det = Determinant_Matrix(matr, n);//знайти детермінант матриці
		cout << "\nMatrix determinant = " << det << endl;//вивести детермінант матриці
		if (det != 0)//якщо детермінант не дорівнює = 0
		{
			for (int i = 0; i < n; i++)//доки є рядки в матриці
			{
				for (int j = 0; j < n; j++)//доки в рядку матриці є елементи
				{
					int m = n - 1;//змінна для знаходження детермінанту та видалення рядка з стовбцем
					double **temp_matr = new double *[m];//ініціалізувати змінну для знаходження детермінанту та видалення рядка з стовбцем
					for (int k = 0; k < m; k++)//доки є рядки в новій матриці
					{
						temp_matr[k] = new double[m];//ініціалізувати змінну для знаходження детермінанту та видалення рядка з стовбцем
					}
					Delete_Row_Column(matr, n, temp_matr, i, j);//видалити рядок та стовбець з матриці
					inver_matr[i][j] = pow(-1.0, i + j + 2) * Determinant_Matrix(temp_matr, m) / det;//знайти елемент оберненої матриці
					Free_Memory(temp_matr, m);//очистити пам'ять
				}
			}
		}
		else//якщо детермінант = 0
		{
			cout << "Matrix determinant = 0, so this matrix is degenerate and does not have inverse matrix" << endl;
		}
		Transpon_Matrix(inver_matr, trans_matr, n);//транспоную матрицю
		cout << "\n\t\t\tInverse \n\n";
		Print_Matrix(trans_matr, n);//виводжу обернену матрицю
		cout << endl;
		Free_Memory(trans_matr, n);//звільнюю пам'ять
		Free_Memory(matr, n);//звільнюю пам'ять
		Free_Memory(inver_matr, n);//звільнюю пам'ять
	}
}

void Random_Matrix()
{
	srand((unsigned)time(NULL));//для задання рандомних елементів матриці
	int n;//змінна для вибору матриці
	int det;//змінна для знаходження детермінанту
	cout << "MENU -> Find inverse matrix -> Create random matrix:\n";
	cout << "Enter matrix size: ";
	cin >> n;//ввести розмір матриці
	if (n <= 1)//якщо розмір матриці менше або дорівнює 1
	{
		cout << "Impossible to find inverse matrix.\n";
	}
	else//якщо розмір матриці більше 1
	{
		cout << endl;
		double **matr = new double *[n];//ініціалізувати розмір матриці
		double **inver_matr = new double *[n];//ініціалізувати розмір оберненої матриці
		double **trans_matr = new double *[n];//ініціалізувати розмір транспонованої матриці
		for (int i = 0; i < n; i++)
		{
			matr[i] = new double[n];//ініціалізувати розмір матриці
			inver_matr[i] = new double[n];//ініціалізувати розмір оберненої матриці
			trans_matr[i] = new double[n];//ініціалізувати розмір транспонованої матриці
		}
		Fill_Random_Inverse_Matrix(matr, n);//заповнити рандомну матрицю
		Print_Matrix(matr, n);//вивести матрицю
		det = Determinant_Matrix(matr, n);//знайти детермінант матриці
		cout << "\nMatrix determinant = " << det << endl;//вивести детермінант матриці
		if (det != 0)//якщо детермінант не дорівнює = 0
		{
			for (int i = 0; i < n; i++)//доки є рядки в матриці
			{
				for (int j = 0; j < n; j++)//доки в рядку матриці є елементи
				{
					int m = n - 1;//змінна для знаходження детермінанту та видалення рядка з стовбцем
					double **temp_matr = new double *[m];//ініціалізувати змінну для знаходження детермінанту та видалення рядка з стовбцем
					for (int k = 0; k < m; k++)//доки є рядки в новій матриці
					{
						temp_matr[k] = new double[m];//ініціалізувати змінну для знаходження детермінанту та видалення рядка з стовбцем
					}
					Delete_Row_Column(matr, n, temp_matr, i, j);//видалити рядок та стовбець з матриці
					inver_matr[i][j] = pow(-1.0, i + j + 2) * Determinant_Matrix(temp_matr, m) / det;//знайти елемент оберненої матриці
					Free_Memory(temp_matr, m);//очистити пам'ять
				}
			}
		}
		else//якщо детермінант дорівнює = 0
		{
			cout << "Matrix determinant = 0, so this matrix is degenerate and does not have inverse matrix" << endl;
		}
		Transpon_Matrix(inver_matr, trans_matr, n);//транспоную матрицю
		cout << "\n\t\t\tInverse \n\n";
		Print_Matrix(trans_matr, n);//виводжу обернену матрицю
		cout << endl << endl;
		Free_Memory(trans_matr, n);//звільнюю пам'ять
		Free_Memory(matr, n);//звільнюю пам'ять
		Free_Memory(inver_matr, n);//звільнюю пам'ять
	}
}

void Transpon_Matrix(double **matr, double **tMatr, int n)//фунція транспонування матриці
{
	for (int i = 0; i < n; i++)//доки є рядки в матриці
	{
		for (int j = 0; j < n; j++)//доки в рядку матриці є елементи
		{
			tMatr[j][i] = matr[i][j];//замінити значення елементів рядка на значення елементів стовбця та навпаки
		}
	}
}

void Free_Memory(double **matr, int n)//Функция освобождения памяти
{
	for (int i = 0; i < n; i++)//доки є рядки або стовбці матриці
	{
		delete[] matr[i];//видалити елементи матриці
	}
	delete[] matr;//видалити матрицю
}

void Fill_Random_Inverse_Matrix(double **matr, int n)//функція заповнення рандомної матриці
{
	for (int i = 0; i < n; i++)//доки є рядки в матриці
	{
		for (int j = 0; j < n; j++)//доки є елементи рядка матриці
		{
			matr[i][j] = rand() % 9 + 1;//надати рандомне значення елементу матриці
		}
	}
}

void Fill_Your_Inverse_Matrix(double **matr, int n)//функція заповнення матриці елементами введеними з клавіатури
{
	for (int i = 0; i < n; i++)//доки є рядки в матриці
	{
		for (int j = 0; j < n; j++)//доки є елементи рядка матриці
		{
			cout << "Enter matrix element: ";
			cin >> matr[i][j];//ввести елемент матриці з клавіатури
		}
	}
	cout << endl;
}

void Choose_Given_Inverse_Matrix(double **matr, int n)//функція вибору заданої матриці
{

	float arr1[1][1];//задаю масив матриці 1
	float arr2[2][2];//задаю масив матриці 2
	float arr3[3][3];//задаю масив матриці 3
	float arr4[4][4];//задаю масив матриці 4
	float arr5[5][5];//задаю масив матриці 5
	FILE *f1 = fopen("Inverse_1.txt", "r");//відкриваю файл з матрицею 1 для читання
	FILE *f2 = fopen("Inverse_2.txt", "r");//відкриваю файл з матрицею 2 для читання
	FILE *f3 = fopen("Inverse_3.txt", "r");//відкриваю файл з матрицею 3 для читання
	FILE *f4 = fopen("Inverse_4.txt", "r");//відкриваю файл з матрицею 4 для читання
	FILE *f5 = fopen("Inverse_5.txt", "r");//відкриваю файл з матрицею 5 для читання

	for (int i = 0; i < 1; i++)//доки є рядки в матриці
	{
		for (int j = 0; j < 1; j++)//доки є елементи рядка
		{
			fscanf(f1, "%f", &arr1[i][j]);//зчитую елемент з файлу
		}
	}
	for (int i = 0; i < 2; i++)//доки є рядки в матриці
	{
		for (int j = 0; j < 2; j++)//доки є елементи рядка
		{
			fscanf(f2, "%f", &arr2[i][j]);//зчитую елемент з файлу
		}
	}
	for (int i = 0; i < 3; i++)//доки є рядки в матриці
	{
		for (int j = 0; j < 3; j++)//доки є елементи рядка
		{
			fscanf(f3, "%f", &arr3[i][j]);//зчитую елемент з файлу
		}
	}
	for (int i = 0; i < 4; i++)//доки є рядки в матриці
	{
		for (int j = 0; j < 4; j++)//доки є елементи рядка
		{
			fscanf(f4, "%f", &arr4[i][j]);//зчитую елемент з файлу
		}
	}
	for (int i = 0; i < 5; i++)//доки є рядки в матриці
	{
		for (int j = 0; j < 5; j++)//доки є елементи рядка
		{
			fscanf(f5, "%f", &arr5[i][j]);//зчитую елемент з файлу
		}
	}

	for (int i = 0; i < n; i++)//доки є рядки в матриці
	{
		for (int j = 0; j < n; j++)//доки є елементи рядка матриці
		{
			if (n == 1)//якщо користувач вибрав матрицю 1
			{
				matr[i][j] = arr1[i][j];//перенести значення елементів матриці 1 в нову матрицю
			}
			if (n == 2)//якщо користувач вибрав матрицю 2
			{
				matr[i][j] = arr2[i][j];//перенести значення елементів матриці 2 в нову матрицю
			}
			if (n == 3)//якщо користувач вибрав матрицю 3
			{
				matr[i][j] = arr3[i][j];//перенести значення елементів матриці 3 в нову матрицю
			}
			if (n == 4)//якщо користувач вибрав матрицю 4
			{
				matr[i][j] = arr4[i][j];//перенести значення елементів матриці 4 в нову матрицю
			}
			if (n == 5)//якщо користувач вибрав матрицю 5
			{
				matr[i][j] = arr5[i][j];//перенести значення елементів матриці 5 в нову матрицю
			}
		}
	}
}

void Print_Matrix(double **matr, int n)//функция печати матрицы
{
	cout << "\t\t\tMatrix:\n\n";
	for (int i = 0; i < n; i++)//доки є рядки в матриці
	{
		for (int j = 0; j < n; j++)//доки є елементи рядка матриці
		{
			cout << setw(13) << matr[i][j];//вивести елемент матриці
		}
		cout << endl;
	}
}

void Delete_Row_Column(double **matr, int n, double **temp_matr, int Row, int Col)//функція видалення рядки та стовбця
{
	int ki = 0;//змінна для проміжної матриці
	for (int i = 0; i < n; i++)//доки є рядки в матриці
	{
		if (i != Row)//якщо рядок не є рядком для видалення
		{
			for (int j = 0, kj = 0; j < n; j++)//доки є елементи рядка
			{
				if (j != Col)//якщо елемент рядка не є елементом рядка для видалення
				{
					temp_matr[ki][kj] = matr[i][j];//надати значення елементу проміжної матриці
					kj++;
				}
			}
			ki++;
		}
	}
}

double Determinant_Matrix(double **matr, int n)//функція для знаходження детермінанту
{
	double temp = 0;//тимчасова змінна для зберігання значення детермінанту
	int k = 1;//степінь
	if (n < 1)//якщо такої матриці не існує
	{
		cout << "This matrix does not exist." << endl;
		return 0;
	}
	else if (n == 1)//якщо розмір матриці 1 на 1
	{
		temp = matr[0][0];//знаходжу значення детермінанту та зберігаю її
	}
	else if (n == 2)//якщо розмір матриці 2 на 2
	{
		temp = matr[0][0] * matr[1][1] - matr[1][0] * matr[0][1];//знаходжу значення детермінанту та зберігаю її
	}
	else//знаходження детермінанту через мінори
	{
		for (int i = 0; i < n; i++)//доки є рядки в матриці
		{
			int m = n - 1;//змінна для знаходження детермінанту та видалення рядка з стовбцем
			double **temp_matr = new double *[m];//ініціалізувати змінну для знаходження детермінанту та видалення рядка з стовбцем
			for (int j = 0; j < m; j++)//доки є рядки в новій матриці
			{
				temp_matr[j] = new double[m];//ініціалізувати змінну для знаходження детермінанту та видалення рядка з стовбцем
			}
			Delete_Row_Column(matr, n, temp_matr, 0, i);//видалення рядка та стовбчика
			temp = temp + k * matr[0][i] * Determinant_Matrix(temp_matr, m);//обчислення детермінанту
			k = -k;//зміна знаку
			Free_Memory(temp_matr, m);//очищення матриці
		}
	}
	return temp;
}

void Print_Given_Inverse_Matrix()
{
	float arr1[1][1];//задаю масив матриці 1
	float arr2[2][2];//задаю масив матриці 2
	float arr3[3][3];//задаю масив матриці 3
	float arr4[4][4];//задаю масив матриці 4
	float arr5[5][5];//задаю масив матриці 5
	FILE *f1 = fopen("Inverse_1.txt", "r");//відкриваю файл з матрицею 1 для читання
	FILE *f2 = fopen("Inverse_2.txt", "r");//відкриваю файл з матрицею 2 для читання
	FILE *f3 = fopen("Inverse_3.txt", "r");//відкриваю файл з матрицею 3 для читання
	FILE *f4 = fopen("Inverse_4.txt", "r");//відкриваю файл з матрицею 4 для читання
	FILE *f5 = fopen("Inverse_5.txt", "r");//відкриваю файл з матрицею 5 для читання

	cout << "\n      Matrix 1" << endl;//вивести матрицю 1
	for (int i = 0; i < 1; i++)//доки є рядки в матриці
	{
		for (int j = 0; j < 1; j++)//доки є елементи рядка
		{
			fscanf(f1, "%f", &arr1[i][j]);//зчитую елемент з файлу
			cout << setw(7) << arr1[i][j];//вивести елемент матриці
		}
		cout << endl;
	}
	cout << endl;
	cout << "      Matrix 2" << endl;//вивести матрицю 2
	for (int i = 0; i < 2; i++)//доки є рядки в матриці
	{
		for (int j = 0; j < 2; j++)//доки є елементи рядка
		{
			fscanf(f2, "%f", &arr2[i][j]);//зчитую елемент з файлу
			cout << setw(7) << arr2[i][j];//вивести елемент матриці
		}
		cout << endl;
	}
	cout << endl;
	cout << "      Matrix 3" << endl;//вивести матрицю 3
	for (int i = 0; i < 3; i++)//доки є рядки в матриці
	{
		for (int j = 0; j < 3; j++)//доки є елементи рядка
		{
			fscanf(f3, "%f", &arr3[i][j]);//зчитую елемент з файлу
			cout << setw(7) << arr3[i][j];//вивести елемент матриці
		}
		cout << endl;
	}
	cout << endl;
	cout << "      Matrix 4" << endl;//вивести матрицю 4
	for (int i = 0; i < 4; i++)//доки є рядки в матриці
	{
		for (int j = 0; j < 4; j++)//доки є елементи рядка
		{
			fscanf(f4, "%f", &arr4[i][j]);//зчитую елемент з файлу
			cout << setw(7) << arr4[i][j];//вивести елемент матриці
		}
		cout << endl;
	}
	cout << endl;
	cout << "      Matrix 5" << endl;//вивести матрицю 5
	for (int i = 0; i < 5; i++)//доки є рядки в матриці
	{
		for (int j = 0; j < 5; j++)//доки є елементи рядка
		{
			fscanf(f5, "%f", &arr5[i][j]);//зчитую елемент з файлу
			cout << setw(7) << arr5[i][j];//вивести елемент матриці
		}
		cout << endl;
	}
	cout << endl << endl;
}
//======================================
//===========МЕТОД ЗЕЙДЕЛЯ==============
//======================================

void Fill_Random_Zeidel_Matrix(double **matrA, double *matrB, int n)//функція заповнення рандомної матриці для методу Зейделя
{
	for (int i = 0; i < n; i++)//доки є рядки в матриці
	{
		for (int j = 0; j < n; j++)//доки є елементи рядка
		{
			if (i == j)//якщо елемент є елементом діагоналі
			{
				matrA[i][j] = rand() % 30 + 20;//надаю значення елементу діагоналі матриці А
			}
			else//якщо елемент не є елементом діагоналі
			{
				matrA[i][j] = rand() % 9 + 1;//надаю значення елементу матриці А
			}
		}
		matrB[i] = rand() % 60 + 50;//надаю значення елементу матриці B
	}
}

void Fill_Your_Zeidel_Matrix(double **matrA, double *matrB, int n)//функція заповнення матриці для методу Зейделя з клавіатури
{
	cout << "The value of the matrix B element must be much larger than the matrix A.\n";
	cout << "The value of the diagonal element matrix A must be much larger than the other elements of matrix A.\n\n";
	for (int i = 0; i < n; i++)//доки є рядки в матриці
	{
		for (int j = 0; j < n; j++)//доки є елементи рядка
		{
			if (i == j)
			{
				cout << "Enter diagonal element of matrix A: ";
				cin >> matrA[i][j];//ввести значення елемента діагоналі матриці А з клавіатури
			}
			else
			{
				cout << "Enter element of matrix A: ";
				cin >> matrA[i][j];//ввести значення елемента матриці А з клавіатури
			}
		}
		cout << "\nEnter element of matrix B: ";
		cin >> matrB[i];//ввести значення елемента матриці B з клавіатури
		cout << endl;
	}
}

void Choose_Given_Zeidel_Matrix(double **matrA, double *matrB, int n)//функція вибору заданої матриці для методу Зейделя
{
	float arrA1[1][1];//задаю масив матриці A1
	float arrA2[2][2];//задаю масив матриці A2
	float arrA3[3][3];//задаю масив матриці A3
	float arrA4[4][4];//задаю масив матриці A4
	float arrA5[5][5];//задаю масив матриці A5
	FILE *fA1 = fopen("Zeidel_A1.txt", "r");//відкриваю файл з матрицею A1 для читання
	FILE *fA2 = fopen("Zeidel_A2.txt", "r");//відкриваю файл з матрицею A2 для читання
	FILE *fA3 = fopen("Zeidel_A3.txt", "r");//відкриваю файл з матрицею A3 для читання
	FILE *fA4 = fopen("Zeidel_A4.txt", "r");//відкриваю файл з матрицею A4 для читання
	FILE *fA5 = fopen("Zeidel_A5.txt", "r");//відкриваю файл з матрицею A5 для читання
	float arrB1[1];//задаю масив матриці B1
	float arrB2[2];//задаю масив матриці B2
	float arrB3[3];//задаю масив матриці B3
	float arrB4[4];//задаю масив матриці B4
	float arrB5[5];//задаю масив матриці B5
	FILE *fB1 = fopen("Zeidel_B1.txt", "r");//відкриваю файл з матрицею B1 для читання
	FILE *fB2 = fopen("Zeidel_B2.txt", "r");//відкриваю файл з матрицею B2 для читання
	FILE *fB3 = fopen("Zeidel_B3.txt", "r");//відкриваю файл з матрицею B3 для читання
	FILE *fB4 = fopen("Zeidel_B4.txt", "r");//відкриваю файл з матрицею B4 для читання
	FILE *fB5 = fopen("Zeidel_B5.txt", "r");//відкриваю файл з матрицею B5 для читання

	for (int i = 0; i < 1; i++)//доки є рядки в матриці
	{
		for (int j = 0; j < 1; j++)//доки є елементи рядка
		{
			fscanf(fA1, "%f", &arrA1[i][j]);//зчитую з файлу елемент матриці А1
		}
		fscanf(fB1, "%f", &arrB1[i]);//зчитую з файлу елемент матриці B1
	}
	for (int i = 0; i < 2; i++)//доки є рядки в матриці
	{
		for (int j = 0; j < 2; j++)//доки є елементи рядка
		{
			fscanf(fA2, "%f", &arrA2[i][j]);//зчитую з файлу елемент матриці А2
		}
		fscanf(fB2, "%f", &arrB2[i]);//зчитую з файлу елемент матриці B2
	}
	for (int i = 0; i < 3; i++)//доки є рядки в матриці
	{
		for (int j = 0; j < 3; j++)//доки є елементи рядка
		{
			fscanf(fA3, "%f", &arrA3[i][j]);//зчитую з файлу елемент матриці А3
		}
		fscanf(fB3, "%f", &arrB3[i]);//зчитую з файлу елемент матриці B3
	}
	for (int i = 0; i < 4; i++)//доки є рядки в матриці
	{
		for (int j = 0; j < 4; j++)//доки є елементи рядка
		{
			fscanf(fA4, "%f", &arrA4[i][j]);//зчитую з файлу елемент матриці А4
		}
		fscanf(fB4, "%f", &arrB4[i]);//зчитую з файлу елемент матриці B4
	}
	for (int i = 0; i < 5; i++)//доки є рядки в матриці
	{
		for (int j = 0; j < 5; j++)//доки є елементи рядка
		{
			fscanf(fA5, "%f", &arrA5[i][j]);//зчитую з файлу елемент матриці А5
		}
		fscanf(fB5, "%f", &arrB5[i]);//зчитую з файлу елемент матриці B5
	}

	for (int i = 0; i < n; i++)//доки є рядки в матриці
	{
		for (int j = 0; j < n; j++)//доки є елементи рядка матриці
		{
			if (n == 1)//якщо користувач вибрав матрицю 1
			{
				matrA[i][j] = arrA1[i][j];//перенести значення елементів матриці А1 в нову матрицю А
				matrB[i] = arrB1[i];//перенести значення елементів матриці B1 в нову матрицю B
			}
			if (n == 2)//якщо користувач вибрав матрицю 2
			{
				matrA[i][j] = arrA2[i][j];//перенести значення елементів матриці А2 в нову матрицю А
				matrB[i] = arrB2[i];//перенести значення елементів матриці B2 в нову матрицю B
			}
			if (n == 3)//якщо користувач вибрав матрицю 3
			{
				matrA[i][j] = arrA3[i][j];//перенести значення елементів матриці А3 в нову матрицю А
				matrB[i] = arrB3[i];//перенести значення елементів матриці B3 в нову матрицю B
			}
			if (n == 4)//якщо користувач вибрав матрицю 4
			{
				matrA[i][j] = arrA4[i][j];//перенести значення елементів матриці А4 в нову матрицю А
				matrB[i] = arrB4[i];//перенести значення елементів матриці B4 в нову матрицю B
			}
			if (n == 5)//якщо користувач вибрав матрицю 5
			{
				matrA[i][j] = arrA5[i][j];//перенести значення елементів матриці А5 в нову матрицю А
				matrB[i] = arrB5[i];//перенести значення елементів матриці B5 в нову матрицю B
			}
		}
	}
}

void Print_Zeidel_Matrix(double **matrA, double *matrB, int n)//функция печати матрицы
{
	for (int i = 0; i < n; i++)//доки є рядки в матриці
	{
		for (int j = 0; j < n; j++)//доки є елементи рядка матриці
		{
			cout << matrA[i][j] << "\t";//вивести елемент матриці А
		}
		cout << "     ";
		cout << matrB[i] << endl;//вивести елемент матриці B
	}
}

void Print_Given_Zeidel_Matrix()//функція виводу заданих матриць
{
	float arrA1[1][1];//задаю масив матриці A1
	float arrA2[2][2];//задаю масив матриці A2
	float arrA3[3][3];//задаю масив матриці A3
	float arrA4[4][4];//задаю масив матриці A4
	float arrA5[5][5];//задаю масив матриці A5
	FILE *fA1 = fopen("Zeidel_A1.txt", "r");//відкриваю файл з матрицею A1 для читання
	FILE *fA2 = fopen("Zeidel_A2.txt", "r");//відкриваю файл з матрицею A2 для читання
	FILE *fA3 = fopen("Zeidel_A3.txt", "r");//відкриваю файл з матрицею A3 для читання
	FILE *fA4 = fopen("Zeidel_A4.txt", "r");//відкриваю файл з матрицею A4 для читання
	FILE *fA5 = fopen("Zeidel_A5.txt", "r");//відкриваю файл з матрицею A5 для читання
	float arrB1[1];//задаю масив матриці B1
	float arrB2[2];//задаю масив матриці B2
	float arrB3[3];//задаю масив матриці B3
	float arrB4[4];//задаю масив матриці B4
	float arrB5[5];//задаю масив матриці B5
	FILE *fB1 = fopen("Zeidel_B1.txt", "r");//відкриваю файл з матрицею B1 для читання
	FILE *fB2 = fopen("Zeidel_B2.txt", "r");//відкриваю файл з матрицею B2 для читання
	FILE *fB3 = fopen("Zeidel_B3.txt", "r");//відкриваю файл з матрицею B3 для читання
	FILE *fB4 = fopen("Zeidel_B4.txt", "r");//відкриваю файл з матрицею B4 для читання
	FILE *fB5 = fopen("Zeidel_B5.txt", "r");//відкриваю файл з матрицею B5 для читання

	cout << "\n      Matrix 1" << endl;//вивести матрицю 1
	for (int i = 0; i < 1; i++)//доки є рядки в матриці
	{
		for (int j = 0; j < 1; j++)//доки є елементи рядка
		{
			fscanf(fA1, "%f", &arrA1[i][j]);//зчитую з файлу елемент матриці А1
			cout << setw(10) << arrA1[i][j];//вивести елемент матриці А1
		}
		fscanf(fB1, "%f", &arrB1[i]);//зчитую з файлу елемент матриці B1
		cout << setw(15) << arrB1[i] << endl;//вивести елемент матриці B1
	}
	cout << endl;
	cout << "      Matrix 2" << endl;//вивести матрицю 2
	for (int i = 0; i < 2; i++)//доки є рядки в матриці
	{
		for (int j = 0; j < 2; j++)//доки є елементи рядка
		{
			fscanf(fA2, "%f", &arrA2[i][j]);//зчитую з файлу елемент матриці А2
			cout << setw(10) << arrA2[i][j];//вивести елемент матриці А2
		}
		fscanf(fB2, "%f", &arrB2[i]);//зчитую з файлу елемент матриці B2
		cout << setw(15) << arrB2[i] << endl;//вивести елемент матриці B2
	}
	cout << endl;
	cout << "      Matrix 3" << endl;//вивести матрицю 3
	for (int i = 0; i < 3; i++)//доки є рядки в матриці
	{
		for (int j = 0; j < 3; j++)//доки є елементи рядка
		{
			fscanf(fA3, "%f", &arrA3[i][j]);//зчитую з файлу елемент матриці А3
			cout << setw(10) << arrA3[i][j];//вивести елемент матриці А3
		}
		fscanf(fB3, "%f", &arrB3[i]);//зчитую з файлу елемент матриці B3
		cout << setw(15) << arrB3[i] << endl;//вивести елемент матриці B3
	}
	cout << endl;
	cout << "      Matrix 4" << endl;//вивести матрицю 4
	for (int i = 0; i < 4; i++)//доки є рядки в матриці
	{
		for (int j = 0; j < 4; j++)//доки є елементи рядка
		{
			fscanf(fA4, "%f", &arrA4[i][j]);//зчитую з файлу елемент матриці А4
			cout << setw(10) << arrA4[i][j];//вивести елемент матриці А4
		}
		fscanf(fB4, "%f", &arrB4[i]);//зчитую з файлу елемент матриці B4
		cout << setw(15) << arrB4[i] << endl;//вивести елемент матриці B4
	}
	cout << endl;
	cout << "      Matrix 5" << endl;//вивести матрицю 5
	for (int i = 0; i < 5; i++)//доки є рядки в матриці
	{
		for (int j = 0; j < 5; j++)//доки є елементи рядка
		{
			fscanf(fA5, "%f", &arrA5[i][j]);//зчитую з файлу елемент матриці А5
			cout << setw(10) << arrA5[i][j];//вивести елемент матриці А5
		}
		fscanf(fB5, "%f", &arrB5[i]);//зчитую з файлу елемент матриці B5
		cout << setw(15) << arrB5[i] << endl;//вивести елемент матриці B5
	}
	cout << endl << endl;
}

void Random_Zeidel()
{
	srand((unsigned)time(NULL));//для задання рандомних елементів матриці
	int n;//змінна розміру матриці
	cout << "MENU -> Find the roots of the SLAE by the Seidel method -> Create random matrix:\n";
	cout << "Enter matrix size: ";
	cin >> n;//ввід розміру матриці
	if (n <= 1)//якщо розмір матриці менше або дорівнює 1
	{
		cout << "Impossible to find roots for this matrix.\n\n";
	}
	else//якщо розмір матриці більше 1
	{
		cout << endl;
		double **matrA = new double *[n];//ініціалізую розмір матриці А
		double *matrB = new double[n];//ініціалізую розмір матриці B
		for (int i = 0; i < n; i++)
		{
			matrA[i] = new double[n];//ініціалізую розмір матриці А
		}
		Fill_Random_Zeidel_Matrix(matrA, matrB, n);//заповню рандомну матрицю
		Print_Zeidel_Matrix(matrA, matrB, n);//вивід елементів матриці

		int k = 1;//змінна для кількості ітерацій
		double *y = new double[n];//масив, для знаходження Х-ів
		double *r = new double[n];//вектор нев'язки
		double *X = new double[n];//масив Х-ів
		double *sum = new double[n];//масив для знаходження вектора нев'язки
		double max = 1;//критерій закінчення
		double per = 0;//змінна для зберігання значення Х (для критерія закінчення)

		for (int i = 0; i < n; i++)//доки э рядки в матриці
		{
			y[i] = 0;//допоміжний масив для знаходження коренів рівняння
			r[i] = 0;//масив векторів нев'язки
			X[i] = 0;//масив коренів рівняння
			sum[i] = 0;//допоміжний масив для знаходження вектора нев'язки
		}

		while (max > 0.000001)//доки змінна більша за 0.000001 (критерій закінчення)
		{
			for (int i = 0; i < n; i++)//доки є рядки в матриці
			{
				y[i] = matrB[i] / matrA[i][i];//елемент допоміжного масиву дорівнює елементу матриці B поділити на елемент діагоналі матриці А того самого рядка
				for (int j = 0; j < n; j++)//доки є елементи в рядку
				{
					if (j == i)//якщо елемент є елементом діагоналі
					{
						continue;//пропустити весь наступний код у циклі
					}
					y[i] = y[i] - matrA[i][j] / matrA[i][i] * X[j];//знаходження елементу допоміжного масиву 
					X[i] = y[i];//присвоїти значення Х-у
					//cout << setw(10) << X[i];//проміжні результати
				}
			}
			max = abs(X[0] - per);//обрахунок критерія закінчення
			per = X[0];//надати значення змінній для знаходження критерія закінчення
			cout << "\nNumber of iterations - " << k << endl << "Roots: \n"; //вивід кількості ітерацій
			for (int i = 0; i < n; i++)//доки є рядки в матриці
			{
				cout << "X[" << i << "] = " << X[i] << endl;//вивід коренів рівняння
			}
			cout << endl;
			k++;//збільшення значення кількості ітерацій
		}
		cout << endl;

		for (int i = 0; i < n; i++)//доки є рядки в матриці
		{
			for (int j = 0; j < n; j++)//доки є елементи в рядку
			{
				sum[i] += matrA[i][j] * X[j];//обрахунок елементів допоміжного масиву для вектора нев'язки
			}
		}

		cout << "Residual vector: \n";
		for (int i = 0; i < n; i++)//доки є рядки в матриці
		{
			r[i] = matrB[i] - sum[i];//обрахунок елемента вектора нев'язки
			cout << "r[" << i << "] = " << r[i] << endl;//вивід елемента вектора нев'зяки
		}

		cout << "\n\nFinal roots:" << endl;
		for (int i = 0; i < n; i++)//доки є рядки в матриці
		{
			cout << "X[" << i << "] = " << X[i] << endl;//вивід значення коренів СЛАР
		}
		cout << endl;

		cout << "Proof of correctness of the solution: " << endl;
		for (int i = 0; i < n; i++)//доки є рядки в матриці
		{
			cout << matrA[0][i] << " * " << X[i];//вивести елемент першого рядка масиву та Х
			if (i != n - 1)//якщо ще є елементи в рядку
			{
				cout << " + ";//вивести ' + '
			}
		}
		cout << " = " << matrB[0] << endl;//вивід першого елемента матриці B

		for (int i = 0; i < n; i++)//доки є рядки в матриці
		{
			cout << matrA[0][i] * X[i];//вивід добутку елемента 1 рядка матриці А та Х-у
			if (i != n - 1)//якщо ще є елементи в рядку
			{
				cout << " + ";//вивести ' + '
			}
		}
		cout << " = " << matrB[0] << endl << endl;//вивід першого елемента матриці B
	}
}

void Given_Zeidel()
{
	int n;//змінна вибору матриці
	cout << "MENU -> Find the roots of the SLAE by the Seidel method -> Use already created matrix:\n";
	Print_Given_Zeidel_Matrix();//вивід заданих матриць
	cout << "Choose matrix: ";
	cin >> n;//вибір матриці
	if (n <= 1)//якщо розмір матриці менше або дорівнює 1
	{
		cout << "Impossible to find roots for this matrix.\n\n";
	}
	else//якщо розмір матриці більше 1
	{
		cout << endl;
		double **matrA = new double *[n];//ініціалізую розмір матриці А
		double *matrB = new double[n];//ініціалізую розмір матриці B
		for (int i = 0; i < n; i++)
		{
			matrA[i] = new double[n];//ініціалізую розмір матриці А
		}
		Choose_Given_Zeidel_Matrix(matrA, matrB, n);//вибір заданої матриці

		int k = 1;//змінна для кількості ітерацій
		double *y = new double[n];//масив, для знаходження Х-ів
		double *r = new double[n];//вектор нев'язки
		double *X = new double[n];//масив Х-ів
		double *sum = new double[n];//масив для знаходження вектора нев'язки
		double max = 1;//критерій закінчення
		double per = 0;//змінна для зберігання значення Х (для критерія закінчення)

		for (int i = 0; i < n; i++)//доки э рядки в матрицш
		{
			y[i] = 0;//допоміжний масив для знаходження коренів рівняння
			r[i] = 0;//масив векторів нев'язки
			X[i] = 0;//масив коренів рівняння
			sum[i] = 0;//допоміжний масив для знаходження вектора нев'язки
		}

		while (max > 0.000001)//доки змінна більша за 0.000001 (критерій закінчення)
		{
			for (int i = 0; i < n; i++)//доки є рядки в матриці
			{
				y[i] = matrB[i] / matrA[i][i];//елемент допоміжного масиву дорівнює елементу матриці B поділити на елемент діагоналі матриці А того самого рядка
				for (int j = 0; j < n; j++)//доки є елементи в рядку
				{
					if (j == i)//якщо елемент є елементом діагоналі
					{
						continue;//пропустити весь наступний код у циклі
					}
					y[i] = y[i] - matrA[i][j] / matrA[i][i] * X[j];//знаходження елементу допоміжного масиву 
					X[i] = y[i];//присвоїти значення Х-у
					//cout << setw(10) << X[i];//проміжні результати
				}
			}
			max = abs(X[0] - per);//обрахунок критерія закінчення
			per = X[0];//надати значення змінній для знаходження критерія закінчення
			cout << "\nNumber of iterations - " << k << endl << "Roots: \n"; //вивід кількості ітерацій
			for (int i = 0; i < n; i++)//доки є рядки в матриці
			{
				cout << "X[" << i << "] = " << X[i] << endl;//вивід коренів рівняння
			}
			cout << endl;
			k++;//збільшення значення кількості ітерацій
		}
		cout << endl;

		for (int i = 0; i < n; i++)//доки є рядки в матриці
		{
			for (int j = 0; j < n; j++)//доки є елементи в рядку
			{
				sum[i] += matrA[i][j] * X[j];//обрахунок елементів допоміжного масиву для вектора нев'язки
			}
		}

		cout << "Residual vector: \n";
		for (int i = 0; i < n; i++)//доки є рядки в матриці
		{
			r[i] = matrB[i] - sum[i];//обрахунок елемента вектора нев'язки
			cout << "r[" << i << "] = " << r[i] << endl;//вивід елемента вектора нев'зяки
		}

		cout << "\n\nFinal roots:" << endl;
		for (int i = 0; i < n; i++)//доки є рядки в матриці
		{
			cout << "X[" << i << "] = " << X[i] << endl;//вивід значення коренів СЛАР
		}
		cout << endl;

		cout << "Proof of correctness of the solution: " << endl;
		for (int i = 0; i < n; i++)//доки є рядки в матриці
		{
			cout << matrA[0][i] << " * " << X[i];//вивести елемент першого рядка масиву та Х
			if (i != n - 1)//якщо ще є елементи в рядку
			{
				cout << " + ";//вивести ' + '
			}
		}
		cout << " = " << matrB[0] << endl;//вивід першого елемента матриці B

		for (int i = 0; i < n; i++)//доки є рядки в матриці
		{
			cout << matrA[0][i] * X[i];//вивід добутку елемента 1 рядка матриці А та Х-у
			if (i != n - 1)//якщо ще є елементи в рядку
			{
				cout << " + ";//вивести ' + '
			}
		}
		cout << " = " << matrB[0] << endl << endl;//вивід першого елемента матриці B
	}
}

void Your_Zeidel()
{
	int n;//змінна розміру матриці
	cout << "MENU -> Find the roots of the SLAE by the Seidel method -> Enter matrix elements from the keyboard:\n";
	cout << "Enter matrix size: ";
	cin >> n;//ввід розміру матриці
	if (n <= 1)//якщо розмір матриці менше або дорівнює 1
	{
		cout << "Impossible to find roots for this matrix.\n\n";
	}
	else//якщо розмір матриці більше 1
	{
		cout << endl;
		double **matrA = new double *[n];//ініціалізую розмір матриці А
		double *matrB = new double[n];//ініціалізую розмір матриці B
		for (int i = 0; i < n; i++)
		{
			matrA[i] = new double[n];//ініціалізую розмір матриці А
		}
		Fill_Your_Zeidel_Matrix(matrA, matrB, n);//заповення матриці з клавіатури
		Print_Zeidel_Matrix(matrA, matrB, n);//вивід матриці

		int k = 1;//змінна для кількості ітерацій
		double *y = new double[n];//масив, для знаходження Х-ів
		double *r = new double[n];//вектор нев'язки
		double *X = new double[n];//масив Х-ів
		double *sum = new double[n];//масив для знаходження вектора нев'язки
		double max = 1;//критерій закінчення
		double per = 0;//змінна для зберігання значення Х (для критерія закінчення)

		for (int i = 0; i < n; i++)//доки э рядки в матрицш
		{
			y[i] = 0;//допоміжний масив для знаходження коренів рівняння
			r[i] = 0;//масив векторів нев'язки
			X[i] = 0;//масив коренів рівняння
			sum[i] = 0;//допоміжний масив для знаходження вектора нев'язки
		}

		while (max > 0.000001)//доки змінна більша за 0.000001 (критерій закінчення)
		{
			for (int i = 0; i < n; i++)//доки є рядки в матриці
			{
				y[i] = matrB[i] / matrA[i][i];//елемент допоміжного масиву дорівнює елементу матриці B поділити на елемент діагоналі матриці А того самого рядка
				for (int j = 0; j < n; j++)//доки є елементи в рядку
				{
					if (j == i)//якщо елемент є елементом діагоналі
					{
						continue;//пропустити весь наступний код у циклі
					}
					y[i] = y[i] - matrA[i][j] / matrA[i][i] * X[j];//знаходження елементу допоміжного масиву 
					X[i] = y[i];//присвоїти значення Х-у
					//cout << setw(10) << X[i];//проміжні результати
				}
			}
			max = abs(X[0] - per);//обрахунок критерія закінчення
			per = X[0];//надати значення змінній для знаходження критерія закінчення
			cout << "\nNumber of iterations - " << k << endl << "Roots: \n"; //вивід кількості ітерацій
			for (int i = 0; i < n; i++)//доки є рядки в матриці
			{
				cout << "X[" << i << "] = " << X[i] << endl;//вивід коренів рівняння
			}
			cout << endl;
			k++;//збільшення значення кількості ітерацій
		}
		cout << endl;

		for (int i = 0; i < n; i++)//доки є рядки в матриці
		{
			for (int j = 0; j < n; j++)//доки є елементи в рядку
			{
				sum[i] += matrA[i][j] * X[j];//обрахунок елементів допоміжного масиву для вектора нев'язки
			}
		}

		cout << "Residual vector: \n";
		for (int i = 0; i < n; i++)//доки є рядки в матриці
		{
			r[i] = matrB[i] - sum[i];//обрахунок елемента вектора нев'язки
			cout << "r[" << i << "] = " << r[i] << endl;//вивід елемента вектора нев'зяки
		}

		cout << "\n\nFinal roots:" << endl;
		for (int i = 0; i < n; i++)//доки є рядки в матриці
		{
			cout << "X[" << i << "] = " << X[i] << endl;//вивід значення коренів СЛАР
		}
		cout << endl;

		cout << "Proof of correctness of the solution: " << endl;
		for (int i = 0; i < n; i++)//доки є рядки в матриці
		{
			cout << matrA[0][i] << " * " << X[i];//вивести елемент першого рядка масиву та Х
			if (i != n - 1)//якщо ще є елементи в рядку
			{
				cout << " + ";//вивести ' + '
			}
		}
		cout << " = " << matrB[0] << endl;//вивід першого елемента матриці B

		for (int i = 0; i < n; i++)//доки є рядки в матриці
		{
			cout << matrA[0][i] * X[i];//вивід добутку елемента 1 рядка матриці А та Х-у
			if (i != n - 1)//якщо ще є елементи в рядку
			{
				cout << " + ";//вивести ' + '
			}
		}
		cout << " = " << matrB[0] << endl << endl;//вивід першого елемента матриці B
	}
}
