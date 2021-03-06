//

#include "pch.h"
#include <iostream>

class matrix
{
private:
	double matr[10][10] = { {0} };
	int rows;
	int columns;
public:
	matrix();
	~matrix();

	bool input();
	bool print();
	bool summMatrix(matrix matr1);
	bool multMatrix(matrix matr1);
	bool transp();
	int getRows()
	{
		return rows;
	}
	int getColumns()
	{
		return columns;
	}
	double getElem(int row, int col)
	{
		if (row<rows && col<columns && row>-1 && col>-1)
		{
			return matr[row][col];
		}
		std::cout << "Connot get element. Index Error!\n";
		return	-1;
	}
};

matrix::matrix()
{
}

matrix::~matrix()
{
}

bool matrix::input()
{
	std::cout << "Insert rows";
	int check;
	std::cin >> check;
	if (check <= 10 && check >= 1)
	{
		rows = check;
	}
	else
	{
		std::cout << "Error";
		return false;
	}

	std::cout << "Insert columns";
	check = 0;
	std::cin >> check;
	if (check <= 10 && check >= 1)
	{
		columns = check;
	}
	else
	{
		std::cout << "Error";
		return false;
	}
	std::cout << "Insert matrix's elements";
	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < columns; j++)
		{
			std::cin >> matr[i][j];
		}
	}
	std::cout << std::endl << "Done";
	return true;
}

bool matrix::print()
{
	std::cout << std::endl << "Printing matrix... \n";
	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < columns; j++)
		{
			std::cout << matr[i][j] << ' ';
		}
		std::cout << std::endl;
	}
	return true;
}

bool matrix::summMatrix(matrix matr1)
{
	if ((rows == matr1.rows) && (columns == matr1.columns))
	{
		for (int i = 0; i < rows; i++)
		{
			for (int j = 0; j < columns; j++)
			{
				matr[i][j] += matr1.matr[i][j];
			}
		}
		std::cout << std::endl << "Done" << std::endl;
		return true;
	}
	else
	{
		std::cout << std::endl << "Error" << std::endl;
		return false;
	}
}

bool matrix::multMatrix(matrix matr1)
{
	if (rows == matr1.columns)
	{
		for (int i = 0; i < rows; i++)
		{
			for (int j = 0; j < matr1.columns; j++)
			{
				int mid = 0;
				for (int k = 0; k < rows; k++)
				{
					mid += matr[i][k] * matr1.matr[k][j];
				}
				matr[i][j] = mid;
			}
		}
		std::cout << std::endl << "Done" << std::endl;
		return true;
	}
	else
	{
		std::cout << std::endl << "Error" << std::endl;
		return false;
	}
}

bool matrix::transp()
{
	int ch;
	if (rows != columns)
	{
		ch = rows;
		rows = columns;
		columns = ch;
	}
	double sw = 0;
	for (int i = 0; i < columns; i++) 
	{
		for (int j = i; j < rows; j++) 
		{
			sw = matr[i][j];
			matr[i][j] = matr[j][i];
			matr[j][i] = sw;
		}
	}
	std::cout << std::endl << "Done" << std::endl;
	return true;
}

class vector : matrix
{
private:
	int size;
	double vec[10];
public:
	double scalMultVector(vector vec2);
	double getElem(int n);
	void vecMult(double k);
};

double vector::scalMultVector(vector vec2)
{
	if (size == vec2.size) 
	{
		double sum = 0;
		for (int i = 0; i < size; i++)
		{
			sum += vec[i] * vec2.vec[i];
		}
		return sum;
	}
	else 
	{
		std::cout << "Error!";
		return -1;
	}
}

double vector::getElem(int n)
{
	if (n < 10 && n > -1)
	{
		return vec[n];
	}
	return -1;
}

void vector::vecMult(double k)
{
	for (int i = 0; i < size; i++)
	{
		vec[i] *= k;
	}
}

int main()
{
	matrix matrA, matrB;
	matrA.input();
	matrB.input();
	matrA.transp();
	matrA.print();
	matrA.summMatrix(matrB);
	matrA.print();
	matrA.multMatrix(matrB);
	matrA.print();
	vector av, bv;
	return 0;
}