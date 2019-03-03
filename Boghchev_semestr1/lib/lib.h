#pragma once

//Naming function
class dynamic_matrix
{
private:
	int rows;
	int columns;
	double *matr;
public:
	dynamic_matrix();
	~dynamic_matrix();

	friend dynamic_matrix operator + (const dynamic_matrix & l, dynamic_matrix & r);
	friend dynamic_matrix operator * (const dynamic_matrix & l, dynamic_matrix & r);
	friend dynamic_matrix operator - (const dynamic_matrix & l, dynamic_matrix & r);
	friend std::ostream & operator << (std::ostream & os, dynamic_matrix & r);
	bool input();
	bool print();
	bool summMatrix(dynamic_matrix matr1);
	bool multMatrix(dynamic_matrix matr1);
	bool transp();
	int getRows()
	{
		return rows;
	}
	int getColumns()
	{
		return columns;
	}
	/*double getElem(int row, int col)
	{
		if (row<rows && col<columns && row>-1 && col>-1)
		{
			return matr[row][col];
		}
		std::cout << "Connot get element. Index Error!\n";
		return	-1;
	}*/
};

void Hello();
