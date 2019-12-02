#include "stdafx.h"
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <ctime>
#include <iomanip>
using namespace std;

void MENU();//������� ����

//---------------������� ��� ����������� �������� �������---------------
void Fill_Random_Inverse_Matrix(double **, int);//������� ���������� �������� �������
void Fill_Your_Inverse_Matrix(double **, int);//������� ���������� ������� � ���������
void Choose_Given_Inverse_Matrix(double **, int);//������� ��� ������ ����� �������, ��� ���� ��� ����
void Print_Matrix(double **, int);//������� ������ �������
void Delete_Row_Column(double **, int, double **, int, int);//������� ������������� ������ �� ������
double Determinant_Matrix(double **matr, int n);//������� ���������� ����������� �������
void Transpon_Matrix(double **matr, double **tMatr, int n);//������� �������������� �������
void Free_Memory(double **matr, int n);//������� �������� ���'��
void Random_Matrix();//������� ��������� �������� �������
void Your_Matrix();//������� ��������� ��� ������� � ���������
void Given_Matrix();//������� ��� ��������� �������, ��� ���� ����
void Print_Given_Inverse_Matrix();//������� ������ ������� ������� ��� ������ �������� �������

//---------------������� ��� ����������� ������ ���� ������� ������� ---------------
void Given_Zeidel();//������� ����'������ ������� ���� ������� �������
void Random_Zeidel();//������� ����'������ ��������� ���� ������� �������
void Your_Zeidel();//������� ����'������ �������� � ��������� ���� ������� �������
void Fill_Random_Zeidel_Matrix(double **matrA, double *matrB, int n);//������� ���������� �������� ������� ��� ������ ������� 
void Fill_Your_Zeidel_Matrix(double **matrA, double *matrB, int n);//������� ���������� ������� ��� ������ ������� � ���������
void Choose_Given_Zeidel_Matrix(double **matrA, double *matrB, int n);//������� ������ ������ ������� ��� ������ �������
void Print_Zeidel_Matrix(double **matrA, double *matrB, int n);//������� ������ ������� ��� ������ �������
void Print_Given_Zeidel_Matrix();//������� ������ ������� ������� ��� ������ �������

int main()
{
	MENU();//������ ������� ����
}

void MENU()//������� ����
{
	system("color F0");//����� ������� ������ �� ����
	int key;//����� ������ ������ ����
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
				Random_Matrix();//������ ������� ����������� �������� ������� �� ��������
				break;
			case 2:
				Your_Matrix();//������ ������� ����������� �������� ������� �� ������� � ���������
				break;
			case 3:
				Given_Matrix();//������ ������� ����������� �������� ������� �� ������ � ����
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
				Random_Zeidel();//������ ������� ����������� ������ ���� �������� �������
				break;
			case 2:
				Your_Zeidel();//������ ������� ����������� ������ ���� ������� ������ � ���������
				break;
			case 3:
				Given_Zeidel();//������ ������� ����������� ������ ���� ������� ������ � ����
				break;
			}
			break;
		case 3:
			cout << "Program finds inverse matrix and roots of the SLAE by the Seidel method.\n";
			cout << "Program was made by Lutsenko Oleksandr IS-8119.\n\n";
			break;
		case 4:
			exit(0);//����� � ��������
		}
	}
}

//======================================
//===========�������� �������===========
//======================================
void Given_Matrix()
{
	int n;//����� ��� ������ �������
	double det;//����� ��� ����������� �����������
	cout << "MENU -> Find inverse matrix -> Use already created matrix:\n";
	Print_Given_Inverse_Matrix();//������� ����� �������
	cout << "Choose matrix: ";
	cin >> n;//������� �������
	if (n <= 1)//���� ����� ������� ����� ��� ������� 1
	{
		cout << "Impossible to find inverse matrix.\n";
	}
	else//���� ����� ������� ����� 1
	{
		cout << endl;
		double **matr = new double *[n];//������������ ����� �������
		double **inver_matr = new double *[n];//������������ ����� �������� �������
		double **trans_matr = new double *[n];//������������ ����� ������������� �������
		for (int i = 0; i < n; i++)
		{
			matr[i] = new double[n];//������������ ����� �������
			inver_matr[i] = new double[n];//������������ ����� �������� �������
			trans_matr[i] = new double[n];//������������ ����� ������������� �������
		}
		Choose_Given_Inverse_Matrix(matr, n);//������� �������
		Print_Matrix(matr, n);//������� �������
		det = Determinant_Matrix(matr, n);//������ ���������� �������
		cout << "\nMatrix determinant = " << det << endl << endl;//������� ���������� �������
		if (det != 0)//���� ���������� �� ������� 0
		{
			for (int i = 0; i < n; i++)//���� � ����� � �������
			{
				for (int j = 0; j < n; j++)//���� � ����� ������� � ��������
				{
					int m = n - 1;//����� ��� ����������� ����������� �� ��������� ����� � ��������
					double **temp_matr = new double *[m];//������������ ����� ��� ����������� ����������� �� ��������� ����� � ��������
					for (int k = 0; k < m; k++)//���� � ����� � ���� �������
					{
						temp_matr[k] = new double[m];//������������ ����� ��� ����������� ����������� �� ��������� ����� � ��������
					}
					Delete_Row_Column(matr, n, temp_matr, i, j);//�������� ����� �� �������� � �������
					inver_matr[i][j] = pow(-1.0, i + j + 2) * Determinant_Matrix(temp_matr, m) / det;//������ ������� �������� �������
					Free_Memory(temp_matr, m);//�������� ���'���
				}
			}
		}
		else//���� ���������� ������� 0
		{
			cout << "Matrix determinant = 0, so this matrix is degenerate and does not have inverse matrix" << endl;
		}
		Transpon_Matrix(inver_matr, trans_matr, n);//������������� �������
		cout << "\n\t\t\tInverse \n\n";
		Print_Matrix(trans_matr, n);//������� �������� �������
		cout << endl << endl;
		Free_Memory(trans_matr, n);//�������� ���'���
		Free_Memory(matr, n);//�������� ���'���
		Free_Memory(inver_matr, n);//�������� ���'���
	}
}

void Your_Matrix()
{
	int n;//����� ��� ������ �������
	double det;//����� ��� ����������� �����������
	cout << "MENU -> Find inverse matrix -> Enter matrix elements from the keyboard:\n";
	cout << "Enter matrix size: ";
	cin >> n;//������ ����� �������
	if (n <= 1)//���� ����� ������� ����� ��� ������� 1
	{
		cout << "Impossible to find inverse matrix.\n";
	}
	else//���� ����� ������� ����� 1
	{
		cout << endl;
		double **matr = new double *[n];//������������ ����� �������
		double **inver_matr = new double *[n];//������������ ����� �������� �������
		double **trans_matr = new double *[n];//������������ ����� ������������� �������
		for (int i = 0; i < n; i++)
		{
			matr[i] = new double[n];//������������ ����� �������
			inver_matr[i] = new double[n];//������������ ����� �������� �������
			trans_matr[i] = new double[n];//������������ ����� ������������� �������
		}
		Fill_Your_Inverse_Matrix(matr, n);//��������� ������� ���������� � ���������
		Print_Matrix(matr, n);//������� �������
		det = Determinant_Matrix(matr, n);//������ ���������� �������
		cout << "\nMatrix determinant = " << det << endl;//������� ���������� �������
		if (det != 0)//���� ���������� �� ������� = 0
		{
			for (int i = 0; i < n; i++)//���� � ����� � �������
			{
				for (int j = 0; j < n; j++)//���� � ����� ������� � ��������
				{
					int m = n - 1;//����� ��� ����������� ����������� �� ��������� ����� � ��������
					double **temp_matr = new double *[m];//������������ ����� ��� ����������� ����������� �� ��������� ����� � ��������
					for (int k = 0; k < m; k++)//���� � ����� � ���� �������
					{
						temp_matr[k] = new double[m];//������������ ����� ��� ����������� ����������� �� ��������� ����� � ��������
					}
					Delete_Row_Column(matr, n, temp_matr, i, j);//�������� ����� �� �������� � �������
					inver_matr[i][j] = pow(-1.0, i + j + 2) * Determinant_Matrix(temp_matr, m) / det;//������ ������� �������� �������
					Free_Memory(temp_matr, m);//�������� ���'���
				}
			}
		}
		else//���� ���������� = 0
		{
			cout << "Matrix determinant = 0, so this matrix is degenerate and does not have inverse matrix" << endl;
		}
		Transpon_Matrix(inver_matr, trans_matr, n);//���������� �������
		cout << "\n\t\t\tInverse \n\n";
		Print_Matrix(trans_matr, n);//������� �������� �������
		cout << endl;
		Free_Memory(trans_matr, n);//������� ���'���
		Free_Memory(matr, n);//������� ���'���
		Free_Memory(inver_matr, n);//������� ���'���
	}
}

void Random_Matrix()
{
	srand((unsigned)time(NULL));//��� ������� ��������� �������� �������
	int n;//����� ��� ������ �������
	int det;//����� ��� ����������� �����������
	cout << "MENU -> Find inverse matrix -> Create random matrix:\n";
	cout << "Enter matrix size: ";
	cin >> n;//������ ����� �������
	if (n <= 1)//���� ����� ������� ����� ��� ������� 1
	{
		cout << "Impossible to find inverse matrix.\n";
	}
	else//���� ����� ������� ����� 1
	{
		cout << endl;
		double **matr = new double *[n];//������������ ����� �������
		double **inver_matr = new double *[n];//������������ ����� �������� �������
		double **trans_matr = new double *[n];//������������ ����� ������������� �������
		for (int i = 0; i < n; i++)
		{
			matr[i] = new double[n];//������������ ����� �������
			inver_matr[i] = new double[n];//������������ ����� �������� �������
			trans_matr[i] = new double[n];//������������ ����� ������������� �������
		}
		Fill_Random_Inverse_Matrix(matr, n);//��������� �������� �������
		Print_Matrix(matr, n);//������� �������
		det = Determinant_Matrix(matr, n);//������ ���������� �������
		cout << "\nMatrix determinant = " << det << endl;//������� ���������� �������
		if (det != 0)//���� ���������� �� ������� = 0
		{
			for (int i = 0; i < n; i++)//���� � ����� � �������
			{
				for (int j = 0; j < n; j++)//���� � ����� ������� � ��������
				{
					int m = n - 1;//����� ��� ����������� ����������� �� ��������� ����� � ��������
					double **temp_matr = new double *[m];//������������ ����� ��� ����������� ����������� �� ��������� ����� � ��������
					for (int k = 0; k < m; k++)//���� � ����� � ���� �������
					{
						temp_matr[k] = new double[m];//������������ ����� ��� ����������� ����������� �� ��������� ����� � ��������
					}
					Delete_Row_Column(matr, n, temp_matr, i, j);//�������� ����� �� �������� � �������
					inver_matr[i][j] = pow(-1.0, i + j + 2) * Determinant_Matrix(temp_matr, m) / det;//������ ������� �������� �������
					Free_Memory(temp_matr, m);//�������� ���'���
				}
			}
		}
		else//���� ���������� ������� = 0
		{
			cout << "Matrix determinant = 0, so this matrix is degenerate and does not have inverse matrix" << endl;
		}
		Transpon_Matrix(inver_matr, trans_matr, n);//���������� �������
		cout << "\n\t\t\tInverse \n\n";
		Print_Matrix(trans_matr, n);//������� �������� �������
		cout << endl << endl;
		Free_Memory(trans_matr, n);//������� ���'���
		Free_Memory(matr, n);//������� ���'���
		Free_Memory(inver_matr, n);//������� ���'���
	}
}

void Transpon_Matrix(double **matr, double **tMatr, int n)//������ �������������� �������
{
	for (int i = 0; i < n; i++)//���� � ����� � �������
	{
		for (int j = 0; j < n; j++)//���� � ����� ������� � ��������
		{
			tMatr[j][i] = matr[i][j];//������� �������� �������� ����� �� �������� �������� ������� �� �������
		}
	}
}

void Free_Memory(double **matr, int n)//������� ������������ ������
{
	for (int i = 0; i < n; i++)//���� � ����� ��� ������� �������
	{
		delete[] matr[i];//�������� �������� �������
	}
	delete[] matr;//�������� �������
}

void Fill_Random_Inverse_Matrix(double **matr, int n)//������� ���������� �������� �������
{
	for (int i = 0; i < n; i++)//���� � ����� � �������
	{
		for (int j = 0; j < n; j++)//���� � �������� ����� �������
		{
			matr[i][j] = rand() % 9 + 1;//������ �������� �������� �������� �������
		}
	}
}

void Fill_Your_Inverse_Matrix(double **matr, int n)//������� ���������� ������� ���������� ��������� � ���������
{
	for (int i = 0; i < n; i++)//���� � ����� � �������
	{
		for (int j = 0; j < n; j++)//���� � �������� ����� �������
		{
			cout << "Enter matrix element: ";
			cin >> matr[i][j];//������ ������� ������� � ���������
		}
	}
	cout << endl;
}

void Choose_Given_Inverse_Matrix(double **matr, int n)//������� ������ ������ �������
{

	float arr1[1][1];//����� ����� ������� 1
	float arr2[2][2];//����� ����� ������� 2
	float arr3[3][3];//����� ����� ������� 3
	float arr4[4][4];//����� ����� ������� 4
	float arr5[5][5];//����� ����� ������� 5
	FILE *f1 = fopen("Inverse_1.txt", "r");//�������� ���� � �������� 1 ��� �������
	FILE *f2 = fopen("Inverse_2.txt", "r");//�������� ���� � �������� 2 ��� �������
	FILE *f3 = fopen("Inverse_3.txt", "r");//�������� ���� � �������� 3 ��� �������
	FILE *f4 = fopen("Inverse_4.txt", "r");//�������� ���� � �������� 4 ��� �������
	FILE *f5 = fopen("Inverse_5.txt", "r");//�������� ���� � �������� 5 ��� �������

	for (int i = 0; i < 1; i++)//���� � ����� � �������
	{
		for (int j = 0; j < 1; j++)//���� � �������� �����
		{
			fscanf(f1, "%f", &arr1[i][j]);//������ ������� � �����
		}
	}
	for (int i = 0; i < 2; i++)//���� � ����� � �������
	{
		for (int j = 0; j < 2; j++)//���� � �������� �����
		{
			fscanf(f2, "%f", &arr2[i][j]);//������ ������� � �����
		}
	}
	for (int i = 0; i < 3; i++)//���� � ����� � �������
	{
		for (int j = 0; j < 3; j++)//���� � �������� �����
		{
			fscanf(f3, "%f", &arr3[i][j]);//������ ������� � �����
		}
	}
	for (int i = 0; i < 4; i++)//���� � ����� � �������
	{
		for (int j = 0; j < 4; j++)//���� � �������� �����
		{
			fscanf(f4, "%f", &arr4[i][j]);//������ ������� � �����
		}
	}
	for (int i = 0; i < 5; i++)//���� � ����� � �������
	{
		for (int j = 0; j < 5; j++)//���� � �������� �����
		{
			fscanf(f5, "%f", &arr5[i][j]);//������ ������� � �����
		}
	}

	for (int i = 0; i < n; i++)//���� � ����� � �������
	{
		for (int j = 0; j < n; j++)//���� � �������� ����� �������
		{
			if (n == 1)//���� ���������� ������ ������� 1
			{
				matr[i][j] = arr1[i][j];//��������� �������� �������� ������� 1 � ���� �������
			}
			if (n == 2)//���� ���������� ������ ������� 2
			{
				matr[i][j] = arr2[i][j];//��������� �������� �������� ������� 2 � ���� �������
			}
			if (n == 3)//���� ���������� ������ ������� 3
			{
				matr[i][j] = arr3[i][j];//��������� �������� �������� ������� 3 � ���� �������
			}
			if (n == 4)//���� ���������� ������ ������� 4
			{
				matr[i][j] = arr4[i][j];//��������� �������� �������� ������� 4 � ���� �������
			}
			if (n == 5)//���� ���������� ������ ������� 5
			{
				matr[i][j] = arr5[i][j];//��������� �������� �������� ������� 5 � ���� �������
			}
		}
	}
}

void Print_Matrix(double **matr, int n)//������� ������ �������
{
	cout << "\t\t\tMatrix:\n\n";
	for (int i = 0; i < n; i++)//���� � ����� � �������
	{
		for (int j = 0; j < n; j++)//���� � �������� ����� �������
		{
			cout << setw(13) << matr[i][j];//������� ������� �������
		}
		cout << endl;
	}
}

void Delete_Row_Column(double **matr, int n, double **temp_matr, int Row, int Col)//������� ��������� ����� �� �������
{
	int ki = 0;//����� ��� ������� �������
	for (int i = 0; i < n; i++)//���� � ����� � �������
	{
		if (i != Row)//���� ����� �� � ������ ��� ���������
		{
			for (int j = 0, kj = 0; j < n; j++)//���� � �������� �����
			{
				if (j != Col)//���� ������� ����� �� � ��������� ����� ��� ���������
				{
					temp_matr[ki][kj] = matr[i][j];//������ �������� �������� ������� �������
					kj++;
				}
			}
			ki++;
		}
	}
}

double Determinant_Matrix(double **matr, int n)//������� ��� ����������� �����������
{
	double temp = 0;//��������� ����� ��� ��������� �������� �����������
	int k = 1;//������
	if (n < 1)//���� ���� ������� �� ����
	{
		cout << "This matrix does not exist." << endl;
		return 0;
	}
	else if (n == 1)//���� ����� ������� 1 �� 1
	{
		temp = matr[0][0];//�������� �������� ����������� �� ������� ��
	}
	else if (n == 2)//���� ����� ������� 2 �� 2
	{
		temp = matr[0][0] * matr[1][1] - matr[1][0] * matr[0][1];//�������� �������� ����������� �� ������� ��
	}
	else//����������� ����������� ����� �����
	{
		for (int i = 0; i < n; i++)//���� � ����� � �������
		{
			int m = n - 1;//����� ��� ����������� ����������� �� ��������� ����� � ��������
			double **temp_matr = new double *[m];//������������ ����� ��� ����������� ����������� �� ��������� ����� � ��������
			for (int j = 0; j < m; j++)//���� � ����� � ���� �������
			{
				temp_matr[j] = new double[m];//������������ ����� ��� ����������� ����������� �� ��������� ����� � ��������
			}
			Delete_Row_Column(matr, n, temp_matr, 0, i);//��������� ����� �� ���������
			temp = temp + k * matr[0][i] * Determinant_Matrix(temp_matr, m);//���������� �����������
			k = -k;//���� �����
			Free_Memory(temp_matr, m);//�������� �������
		}
	}
	return temp;
}

void Print_Given_Inverse_Matrix()
{
	float arr1[1][1];//����� ����� ������� 1
	float arr2[2][2];//����� ����� ������� 2
	float arr3[3][3];//����� ����� ������� 3
	float arr4[4][4];//����� ����� ������� 4
	float arr5[5][5];//����� ����� ������� 5
	FILE *f1 = fopen("Inverse_1.txt", "r");//�������� ���� � �������� 1 ��� �������
	FILE *f2 = fopen("Inverse_2.txt", "r");//�������� ���� � �������� 2 ��� �������
	FILE *f3 = fopen("Inverse_3.txt", "r");//�������� ���� � �������� 3 ��� �������
	FILE *f4 = fopen("Inverse_4.txt", "r");//�������� ���� � �������� 4 ��� �������
	FILE *f5 = fopen("Inverse_5.txt", "r");//�������� ���� � �������� 5 ��� �������

	cout << "\n      Matrix 1" << endl;//������� ������� 1
	for (int i = 0; i < 1; i++)//���� � ����� � �������
	{
		for (int j = 0; j < 1; j++)//���� � �������� �����
		{
			fscanf(f1, "%f", &arr1[i][j]);//������ ������� � �����
			cout << setw(7) << arr1[i][j];//������� ������� �������
		}
		cout << endl;
	}
	cout << endl;
	cout << "      Matrix 2" << endl;//������� ������� 2
	for (int i = 0; i < 2; i++)//���� � ����� � �������
	{
		for (int j = 0; j < 2; j++)//���� � �������� �����
		{
			fscanf(f2, "%f", &arr2[i][j]);//������ ������� � �����
			cout << setw(7) << arr2[i][j];//������� ������� �������
		}
		cout << endl;
	}
	cout << endl;
	cout << "      Matrix 3" << endl;//������� ������� 3
	for (int i = 0; i < 3; i++)//���� � ����� � �������
	{
		for (int j = 0; j < 3; j++)//���� � �������� �����
		{
			fscanf(f3, "%f", &arr3[i][j]);//������ ������� � �����
			cout << setw(7) << arr3[i][j];//������� ������� �������
		}
		cout << endl;
	}
	cout << endl;
	cout << "      Matrix 4" << endl;//������� ������� 4
	for (int i = 0; i < 4; i++)//���� � ����� � �������
	{
		for (int j = 0; j < 4; j++)//���� � �������� �����
		{
			fscanf(f4, "%f", &arr4[i][j]);//������ ������� � �����
			cout << setw(7) << arr4[i][j];//������� ������� �������
		}
		cout << endl;
	}
	cout << endl;
	cout << "      Matrix 5" << endl;//������� ������� 5
	for (int i = 0; i < 5; i++)//���� � ����� � �������
	{
		for (int j = 0; j < 5; j++)//���� � �������� �����
		{
			fscanf(f5, "%f", &arr5[i][j]);//������ ������� � �����
			cout << setw(7) << arr5[i][j];//������� ������� �������
		}
		cout << endl;
	}
	cout << endl << endl;
}
//======================================
//===========����� �������==============
//======================================

void Fill_Random_Zeidel_Matrix(double **matrA, double *matrB, int n)//������� ���������� �������� ������� ��� ������ �������
{
	for (int i = 0; i < n; i++)//���� � ����� � �������
	{
		for (int j = 0; j < n; j++)//���� � �������� �����
		{
			if (i == j)//���� ������� � ��������� �������
			{
				matrA[i][j] = rand() % 30 + 20;//����� �������� �������� ������� ������� �
			}
			else//���� ������� �� � ��������� �������
			{
				matrA[i][j] = rand() % 9 + 1;//����� �������� �������� ������� �
			}
		}
		matrB[i] = rand() % 60 + 50;//����� �������� �������� ������� B
	}
}

void Fill_Your_Zeidel_Matrix(double **matrA, double *matrB, int n)//������� ���������� ������� ��� ������ ������� � ���������
{
	cout << "The value of the matrix B element must be much larger than the matrix A.\n";
	cout << "The value of the diagonal element matrix A must be much larger than the other elements of matrix A.\n\n";
	for (int i = 0; i < n; i++)//���� � ����� � �������
	{
		for (int j = 0; j < n; j++)//���� � �������� �����
		{
			if (i == j)
			{
				cout << "Enter diagonal element of matrix A: ";
				cin >> matrA[i][j];//������ �������� �������� ������� ������� � � ���������
			}
			else
			{
				cout << "Enter element of matrix A: ";
				cin >> matrA[i][j];//������ �������� �������� ������� � � ���������
			}
		}
		cout << "\nEnter element of matrix B: ";
		cin >> matrB[i];//������ �������� �������� ������� B � ���������
		cout << endl;
	}
}

void Choose_Given_Zeidel_Matrix(double **matrA, double *matrB, int n)//������� ������ ������ ������� ��� ������ �������
{
	float arrA1[1][1];//����� ����� ������� A1
	float arrA2[2][2];//����� ����� ������� A2
	float arrA3[3][3];//����� ����� ������� A3
	float arrA4[4][4];//����� ����� ������� A4
	float arrA5[5][5];//����� ����� ������� A5
	FILE *fA1 = fopen("Zeidel_A1.txt", "r");//�������� ���� � �������� A1 ��� �������
	FILE *fA2 = fopen("Zeidel_A2.txt", "r");//�������� ���� � �������� A2 ��� �������
	FILE *fA3 = fopen("Zeidel_A3.txt", "r");//�������� ���� � �������� A3 ��� �������
	FILE *fA4 = fopen("Zeidel_A4.txt", "r");//�������� ���� � �������� A4 ��� �������
	FILE *fA5 = fopen("Zeidel_A5.txt", "r");//�������� ���� � �������� A5 ��� �������
	float arrB1[1];//����� ����� ������� B1
	float arrB2[2];//����� ����� ������� B2
	float arrB3[3];//����� ����� ������� B3
	float arrB4[4];//����� ����� ������� B4
	float arrB5[5];//����� ����� ������� B5
	FILE *fB1 = fopen("Zeidel_B1.txt", "r");//�������� ���� � �������� B1 ��� �������
	FILE *fB2 = fopen("Zeidel_B2.txt", "r");//�������� ���� � �������� B2 ��� �������
	FILE *fB3 = fopen("Zeidel_B3.txt", "r");//�������� ���� � �������� B3 ��� �������
	FILE *fB4 = fopen("Zeidel_B4.txt", "r");//�������� ���� � �������� B4 ��� �������
	FILE *fB5 = fopen("Zeidel_B5.txt", "r");//�������� ���� � �������� B5 ��� �������

	for (int i = 0; i < 1; i++)//���� � ����� � �������
	{
		for (int j = 0; j < 1; j++)//���� � �������� �����
		{
			fscanf(fA1, "%f", &arrA1[i][j]);//������ � ����� ������� ������� �1
		}
		fscanf(fB1, "%f", &arrB1[i]);//������ � ����� ������� ������� B1
	}
	for (int i = 0; i < 2; i++)//���� � ����� � �������
	{
		for (int j = 0; j < 2; j++)//���� � �������� �����
		{
			fscanf(fA2, "%f", &arrA2[i][j]);//������ � ����� ������� ������� �2
		}
		fscanf(fB2, "%f", &arrB2[i]);//������ � ����� ������� ������� B2
	}
	for (int i = 0; i < 3; i++)//���� � ����� � �������
	{
		for (int j = 0; j < 3; j++)//���� � �������� �����
		{
			fscanf(fA3, "%f", &arrA3[i][j]);//������ � ����� ������� ������� �3
		}
		fscanf(fB3, "%f", &arrB3[i]);//������ � ����� ������� ������� B3
	}
	for (int i = 0; i < 4; i++)//���� � ����� � �������
	{
		for (int j = 0; j < 4; j++)//���� � �������� �����
		{
			fscanf(fA4, "%f", &arrA4[i][j]);//������ � ����� ������� ������� �4
		}
		fscanf(fB4, "%f", &arrB4[i]);//������ � ����� ������� ������� B4
	}
	for (int i = 0; i < 5; i++)//���� � ����� � �������
	{
		for (int j = 0; j < 5; j++)//���� � �������� �����
		{
			fscanf(fA5, "%f", &arrA5[i][j]);//������ � ����� ������� ������� �5
		}
		fscanf(fB5, "%f", &arrB5[i]);//������ � ����� ������� ������� B5
	}

	for (int i = 0; i < n; i++)//���� � ����� � �������
	{
		for (int j = 0; j < n; j++)//���� � �������� ����� �������
		{
			if (n == 1)//���� ���������� ������ ������� 1
			{
				matrA[i][j] = arrA1[i][j];//��������� �������� �������� ������� �1 � ���� ������� �
				matrB[i] = arrB1[i];//��������� �������� �������� ������� B1 � ���� ������� B
			}
			if (n == 2)//���� ���������� ������ ������� 2
			{
				matrA[i][j] = arrA2[i][j];//��������� �������� �������� ������� �2 � ���� ������� �
				matrB[i] = arrB2[i];//��������� �������� �������� ������� B2 � ���� ������� B
			}
			if (n == 3)//���� ���������� ������ ������� 3
			{
				matrA[i][j] = arrA3[i][j];//��������� �������� �������� ������� �3 � ���� ������� �
				matrB[i] = arrB3[i];//��������� �������� �������� ������� B3 � ���� ������� B
			}
			if (n == 4)//���� ���������� ������ ������� 4
			{
				matrA[i][j] = arrA4[i][j];//��������� �������� �������� ������� �4 � ���� ������� �
				matrB[i] = arrB4[i];//��������� �������� �������� ������� B4 � ���� ������� B
			}
			if (n == 5)//���� ���������� ������ ������� 5
			{
				matrA[i][j] = arrA5[i][j];//��������� �������� �������� ������� �5 � ���� ������� �
				matrB[i] = arrB5[i];//��������� �������� �������� ������� B5 � ���� ������� B
			}
		}
	}
}

void Print_Zeidel_Matrix(double **matrA, double *matrB, int n)//������� ������ �������
{
	for (int i = 0; i < n; i++)//���� � ����� � �������
	{
		for (int j = 0; j < n; j++)//���� � �������� ����� �������
		{
			cout << matrA[i][j] << "\t";//������� ������� ������� �
		}
		cout << "     ";
		cout << matrB[i] << endl;//������� ������� ������� B
	}
}

void Print_Given_Zeidel_Matrix()//������� ������ ������� �������
{
	float arrA1[1][1];//����� ����� ������� A1
	float arrA2[2][2];//����� ����� ������� A2
	float arrA3[3][3];//����� ����� ������� A3
	float arrA4[4][4];//����� ����� ������� A4
	float arrA5[5][5];//����� ����� ������� A5
	FILE *fA1 = fopen("Zeidel_A1.txt", "r");//�������� ���� � �������� A1 ��� �������
	FILE *fA2 = fopen("Zeidel_A2.txt", "r");//�������� ���� � �������� A2 ��� �������
	FILE *fA3 = fopen("Zeidel_A3.txt", "r");//�������� ���� � �������� A3 ��� �������
	FILE *fA4 = fopen("Zeidel_A4.txt", "r");//�������� ���� � �������� A4 ��� �������
	FILE *fA5 = fopen("Zeidel_A5.txt", "r");//�������� ���� � �������� A5 ��� �������
	float arrB1[1];//����� ����� ������� B1
	float arrB2[2];//����� ����� ������� B2
	float arrB3[3];//����� ����� ������� B3
	float arrB4[4];//����� ����� ������� B4
	float arrB5[5];//����� ����� ������� B5
	FILE *fB1 = fopen("Zeidel_B1.txt", "r");//�������� ���� � �������� B1 ��� �������
	FILE *fB2 = fopen("Zeidel_B2.txt", "r");//�������� ���� � �������� B2 ��� �������
	FILE *fB3 = fopen("Zeidel_B3.txt", "r");//�������� ���� � �������� B3 ��� �������
	FILE *fB4 = fopen("Zeidel_B4.txt", "r");//�������� ���� � �������� B4 ��� �������
	FILE *fB5 = fopen("Zeidel_B5.txt", "r");//�������� ���� � �������� B5 ��� �������

	cout << "\n      Matrix 1" << endl;//������� ������� 1
	for (int i = 0; i < 1; i++)//���� � ����� � �������
	{
		for (int j = 0; j < 1; j++)//���� � �������� �����
		{
			fscanf(fA1, "%f", &arrA1[i][j]);//������ � ����� ������� ������� �1
			cout << setw(10) << arrA1[i][j];//������� ������� ������� �1
		}
		fscanf(fB1, "%f", &arrB1[i]);//������ � ����� ������� ������� B1
		cout << setw(15) << arrB1[i] << endl;//������� ������� ������� B1
	}
	cout << endl;
	cout << "      Matrix 2" << endl;//������� ������� 2
	for (int i = 0; i < 2; i++)//���� � ����� � �������
	{
		for (int j = 0; j < 2; j++)//���� � �������� �����
		{
			fscanf(fA2, "%f", &arrA2[i][j]);//������ � ����� ������� ������� �2
			cout << setw(10) << arrA2[i][j];//������� ������� ������� �2
		}
		fscanf(fB2, "%f", &arrB2[i]);//������ � ����� ������� ������� B2
		cout << setw(15) << arrB2[i] << endl;//������� ������� ������� B2
	}
	cout << endl;
	cout << "      Matrix 3" << endl;//������� ������� 3
	for (int i = 0; i < 3; i++)//���� � ����� � �������
	{
		for (int j = 0; j < 3; j++)//���� � �������� �����
		{
			fscanf(fA3, "%f", &arrA3[i][j]);//������ � ����� ������� ������� �3
			cout << setw(10) << arrA3[i][j];//������� ������� ������� �3
		}
		fscanf(fB3, "%f", &arrB3[i]);//������ � ����� ������� ������� B3
		cout << setw(15) << arrB3[i] << endl;//������� ������� ������� B3
	}
	cout << endl;
	cout << "      Matrix 4" << endl;//������� ������� 4
	for (int i = 0; i < 4; i++)//���� � ����� � �������
	{
		for (int j = 0; j < 4; j++)//���� � �������� �����
		{
			fscanf(fA4, "%f", &arrA4[i][j]);//������ � ����� ������� ������� �4
			cout << setw(10) << arrA4[i][j];//������� ������� ������� �4
		}
		fscanf(fB4, "%f", &arrB4[i]);//������ � ����� ������� ������� B4
		cout << setw(15) << arrB4[i] << endl;//������� ������� ������� B4
	}
	cout << endl;
	cout << "      Matrix 5" << endl;//������� ������� 5
	for (int i = 0; i < 5; i++)//���� � ����� � �������
	{
		for (int j = 0; j < 5; j++)//���� � �������� �����
		{
			fscanf(fA5, "%f", &arrA5[i][j]);//������ � ����� ������� ������� �5
			cout << setw(10) << arrA5[i][j];//������� ������� ������� �5
		}
		fscanf(fB5, "%f", &arrB5[i]);//������ � ����� ������� ������� B5
		cout << setw(15) << arrB5[i] << endl;//������� ������� ������� B5
	}
	cout << endl << endl;
}

void Random_Zeidel()
{
	srand((unsigned)time(NULL));//��� ������� ��������� �������� �������
	int n;//����� ������ �������
	cout << "MENU -> Find the roots of the SLAE by the Seidel method -> Create random matrix:\n";
	cout << "Enter matrix size: ";
	cin >> n;//��� ������ �������
	if (n <= 1)//���� ����� ������� ����� ��� ������� 1
	{
		cout << "Impossible to find roots for this matrix.\n\n";
	}
	else//���� ����� ������� ����� 1
	{
		cout << endl;
		double **matrA = new double *[n];//��������� ����� ������� �
		double *matrB = new double[n];//��������� ����� ������� B
		for (int i = 0; i < n; i++)
		{
			matrA[i] = new double[n];//��������� ����� ������� �
		}
		Fill_Random_Zeidel_Matrix(matrA, matrB, n);//������� �������� �������
		Print_Zeidel_Matrix(matrA, matrB, n);//���� �������� �������

		int k = 1;//����� ��� ������� ��������
		double *y = new double[n];//�����, ��� ����������� �-��
		double *r = new double[n];//������ ���'����
		double *X = new double[n];//����� �-��
		double *sum = new double[n];//����� ��� ����������� ������� ���'����
		double max = 1;//������� ���������
		double per = 0;//����� ��� ��������� �������� � (��� ������� ���������)

		for (int i = 0; i < n; i++)//���� � ����� � �������
		{
			y[i] = 0;//��������� ����� ��� ����������� ������ �������
			r[i] = 0;//����� ������� ���'����
			X[i] = 0;//����� ������ �������
			sum[i] = 0;//��������� ����� ��� ����������� ������� ���'����
		}

		while (max > 0.000001)//���� ����� ����� �� 0.000001 (������� ���������)
		{
			for (int i = 0; i < n; i++)//���� � ����� � �������
			{
				y[i] = matrB[i] / matrA[i][i];//������� ���������� ������ ������� �������� ������� B ������� �� ������� ������� ������� � ���� ������ �����
				for (int j = 0; j < n; j++)//���� � �������� � �����
				{
					if (j == i)//���� ������� � ��������� �������
					{
						continue;//���������� ���� ��������� ��� � ����
					}
					y[i] = y[i] - matrA[i][j] / matrA[i][i] * X[j];//����������� �������� ���������� ������ 
					X[i] = y[i];//�������� �������� �-�
					//cout << setw(10) << X[i];//������ ����������
				}
			}
			max = abs(X[0] - per);//��������� ������� ���������
			per = X[0];//������ �������� ����� ��� ����������� ������� ���������
			cout << "\nNumber of iterations - " << k << endl << "Roots: \n"; //���� ������� ��������
			for (int i = 0; i < n; i++)//���� � ����� � �������
			{
				cout << "X[" << i << "] = " << X[i] << endl;//���� ������ �������
			}
			cout << endl;
			k++;//��������� �������� ������� ��������
		}
		cout << endl;

		for (int i = 0; i < n; i++)//���� � ����� � �������
		{
			for (int j = 0; j < n; j++)//���� � �������� � �����
			{
				sum[i] += matrA[i][j] * X[j];//��������� �������� ���������� ������ ��� ������� ���'����
			}
		}

		cout << "Residual vector: \n";
		for (int i = 0; i < n; i++)//���� � ����� � �������
		{
			r[i] = matrB[i] - sum[i];//��������� �������� ������� ���'����
			cout << "r[" << i << "] = " << r[i] << endl;//���� �������� ������� ���'����
		}

		cout << "\n\nFinal roots:" << endl;
		for (int i = 0; i < n; i++)//���� � ����� � �������
		{
			cout << "X[" << i << "] = " << X[i] << endl;//���� �������� ������ ����
		}
		cout << endl;

		cout << "Proof of correctness of the solution: " << endl;
		for (int i = 0; i < n; i++)//���� � ����� � �������
		{
			cout << matrA[0][i] << " * " << X[i];//������� ������� ������� ����� ������ �� �
			if (i != n - 1)//���� �� � �������� � �����
			{
				cout << " + ";//������� ' + '
			}
		}
		cout << " = " << matrB[0] << endl;//���� ������� �������� ������� B

		for (int i = 0; i < n; i++)//���� � ����� � �������
		{
			cout << matrA[0][i] * X[i];//���� ������� �������� 1 ����� ������� � �� �-�
			if (i != n - 1)//���� �� � �������� � �����
			{
				cout << " + ";//������� ' + '
			}
		}
		cout << " = " << matrB[0] << endl << endl;//���� ������� �������� ������� B
	}
}

void Given_Zeidel()
{
	int n;//����� ������ �������
	cout << "MENU -> Find the roots of the SLAE by the Seidel method -> Use already created matrix:\n";
	Print_Given_Zeidel_Matrix();//���� ������� �������
	cout << "Choose matrix: ";
	cin >> n;//���� �������
	if (n <= 1)//���� ����� ������� ����� ��� ������� 1
	{
		cout << "Impossible to find roots for this matrix.\n\n";
	}
	else//���� ����� ������� ����� 1
	{
		cout << endl;
		double **matrA = new double *[n];//��������� ����� ������� �
		double *matrB = new double[n];//��������� ����� ������� B
		for (int i = 0; i < n; i++)
		{
			matrA[i] = new double[n];//��������� ����� ������� �
		}
		Choose_Given_Zeidel_Matrix(matrA, matrB, n);//���� ������ �������

		int k = 1;//����� ��� ������� ��������
		double *y = new double[n];//�����, ��� ����������� �-��
		double *r = new double[n];//������ ���'����
		double *X = new double[n];//����� �-��
		double *sum = new double[n];//����� ��� ����������� ������� ���'����
		double max = 1;//������� ���������
		double per = 0;//����� ��� ��������� �������� � (��� ������� ���������)

		for (int i = 0; i < n; i++)//���� � ����� � �������
		{
			y[i] = 0;//��������� ����� ��� ����������� ������ �������
			r[i] = 0;//����� ������� ���'����
			X[i] = 0;//����� ������ �������
			sum[i] = 0;//��������� ����� ��� ����������� ������� ���'����
		}

		while (max > 0.000001)//���� ����� ����� �� 0.000001 (������� ���������)
		{
			for (int i = 0; i < n; i++)//���� � ����� � �������
			{
				y[i] = matrB[i] / matrA[i][i];//������� ���������� ������ ������� �������� ������� B ������� �� ������� ������� ������� � ���� ������ �����
				for (int j = 0; j < n; j++)//���� � �������� � �����
				{
					if (j == i)//���� ������� � ��������� �������
					{
						continue;//���������� ���� ��������� ��� � ����
					}
					y[i] = y[i] - matrA[i][j] / matrA[i][i] * X[j];//����������� �������� ���������� ������ 
					X[i] = y[i];//�������� �������� �-�
					//cout << setw(10) << X[i];//������ ����������
				}
			}
			max = abs(X[0] - per);//��������� ������� ���������
			per = X[0];//������ �������� ����� ��� ����������� ������� ���������
			cout << "\nNumber of iterations - " << k << endl << "Roots: \n"; //���� ������� ��������
			for (int i = 0; i < n; i++)//���� � ����� � �������
			{
				cout << "X[" << i << "] = " << X[i] << endl;//���� ������ �������
			}
			cout << endl;
			k++;//��������� �������� ������� ��������
		}
		cout << endl;

		for (int i = 0; i < n; i++)//���� � ����� � �������
		{
			for (int j = 0; j < n; j++)//���� � �������� � �����
			{
				sum[i] += matrA[i][j] * X[j];//��������� �������� ���������� ������ ��� ������� ���'����
			}
		}

		cout << "Residual vector: \n";
		for (int i = 0; i < n; i++)//���� � ����� � �������
		{
			r[i] = matrB[i] - sum[i];//��������� �������� ������� ���'����
			cout << "r[" << i << "] = " << r[i] << endl;//���� �������� ������� ���'����
		}

		cout << "\n\nFinal roots:" << endl;
		for (int i = 0; i < n; i++)//���� � ����� � �������
		{
			cout << "X[" << i << "] = " << X[i] << endl;//���� �������� ������ ����
		}
		cout << endl;

		cout << "Proof of correctness of the solution: " << endl;
		for (int i = 0; i < n; i++)//���� � ����� � �������
		{
			cout << matrA[0][i] << " * " << X[i];//������� ������� ������� ����� ������ �� �
			if (i != n - 1)//���� �� � �������� � �����
			{
				cout << " + ";//������� ' + '
			}
		}
		cout << " = " << matrB[0] << endl;//���� ������� �������� ������� B

		for (int i = 0; i < n; i++)//���� � ����� � �������
		{
			cout << matrA[0][i] * X[i];//���� ������� �������� 1 ����� ������� � �� �-�
			if (i != n - 1)//���� �� � �������� � �����
			{
				cout << " + ";//������� ' + '
			}
		}
		cout << " = " << matrB[0] << endl << endl;//���� ������� �������� ������� B
	}
}

void Your_Zeidel()
{
	int n;//����� ������ �������
	cout << "MENU -> Find the roots of the SLAE by the Seidel method -> Enter matrix elements from the keyboard:\n";
	cout << "Enter matrix size: ";
	cin >> n;//��� ������ �������
	if (n <= 1)//���� ����� ������� ����� ��� ������� 1
	{
		cout << "Impossible to find roots for this matrix.\n\n";
	}
	else//���� ����� ������� ����� 1
	{
		cout << endl;
		double **matrA = new double *[n];//��������� ����� ������� �
		double *matrB = new double[n];//��������� ����� ������� B
		for (int i = 0; i < n; i++)
		{
			matrA[i] = new double[n];//��������� ����� ������� �
		}
		Fill_Your_Zeidel_Matrix(matrA, matrB, n);//��������� ������� � ���������
		Print_Zeidel_Matrix(matrA, matrB, n);//���� �������

		int k = 1;//����� ��� ������� ��������
		double *y = new double[n];//�����, ��� ����������� �-��
		double *r = new double[n];//������ ���'����
		double *X = new double[n];//����� �-��
		double *sum = new double[n];//����� ��� ����������� ������� ���'����
		double max = 1;//������� ���������
		double per = 0;//����� ��� ��������� �������� � (��� ������� ���������)

		for (int i = 0; i < n; i++)//���� � ����� � �������
		{
			y[i] = 0;//��������� ����� ��� ����������� ������ �������
			r[i] = 0;//����� ������� ���'����
			X[i] = 0;//����� ������ �������
			sum[i] = 0;//��������� ����� ��� ����������� ������� ���'����
		}

		while (max > 0.000001)//���� ����� ����� �� 0.000001 (������� ���������)
		{
			for (int i = 0; i < n; i++)//���� � ����� � �������
			{
				y[i] = matrB[i] / matrA[i][i];//������� ���������� ������ ������� �������� ������� B ������� �� ������� ������� ������� � ���� ������ �����
				for (int j = 0; j < n; j++)//���� � �������� � �����
				{
					if (j == i)//���� ������� � ��������� �������
					{
						continue;//���������� ���� ��������� ��� � ����
					}
					y[i] = y[i] - matrA[i][j] / matrA[i][i] * X[j];//����������� �������� ���������� ������ 
					X[i] = y[i];//�������� �������� �-�
					//cout << setw(10) << X[i];//������ ����������
				}
			}
			max = abs(X[0] - per);//��������� ������� ���������
			per = X[0];//������ �������� ����� ��� ����������� ������� ���������
			cout << "\nNumber of iterations - " << k << endl << "Roots: \n"; //���� ������� ��������
			for (int i = 0; i < n; i++)//���� � ����� � �������
			{
				cout << "X[" << i << "] = " << X[i] << endl;//���� ������ �������
			}
			cout << endl;
			k++;//��������� �������� ������� ��������
		}
		cout << endl;

		for (int i = 0; i < n; i++)//���� � ����� � �������
		{
			for (int j = 0; j < n; j++)//���� � �������� � �����
			{
				sum[i] += matrA[i][j] * X[j];//��������� �������� ���������� ������ ��� ������� ���'����
			}
		}

		cout << "Residual vector: \n";
		for (int i = 0; i < n; i++)//���� � ����� � �������
		{
			r[i] = matrB[i] - sum[i];//��������� �������� ������� ���'����
			cout << "r[" << i << "] = " << r[i] << endl;//���� �������� ������� ���'����
		}

		cout << "\n\nFinal roots:" << endl;
		for (int i = 0; i < n; i++)//���� � ����� � �������
		{
			cout << "X[" << i << "] = " << X[i] << endl;//���� �������� ������ ����
		}
		cout << endl;

		cout << "Proof of correctness of the solution: " << endl;
		for (int i = 0; i < n; i++)//���� � ����� � �������
		{
			cout << matrA[0][i] << " * " << X[i];//������� ������� ������� ����� ������ �� �
			if (i != n - 1)//���� �� � �������� � �����
			{
				cout << " + ";//������� ' + '
			}
		}
		cout << " = " << matrB[0] << endl;//���� ������� �������� ������� B

		for (int i = 0; i < n; i++)//���� � ����� � �������
		{
			cout << matrA[0][i] * X[i];//���� ������� �������� 1 ����� ������� � �� �-�
			if (i != n - 1)//���� �� � �������� � �����
			{
				cout << " + ";//������� ' + '
			}
		}
		cout << " = " << matrB[0] << endl << endl;//���� ������� �������� ������� B
	}
}
