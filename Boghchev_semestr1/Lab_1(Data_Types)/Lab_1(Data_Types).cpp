// Lab 1 Sructure of a programm, data types, main operators
#include "pch.h"
#include <iostream>//enable libraries

int main()// "Entry point"
{
	//STD - field of visability
	// there is a part of std in the iostream
	// \n- new line \t-tab \" "\  */
	std::cout << "\"Hello, World!\"\n";
	std::cout << "Hello, World!\r";
	std::cout << "\'Hello, World!\'\t";
	std::cout << "Hello, World!\t";
	std::cout << "\*Hello, World!\*";
	//naming variebles/data type
	//int a;
	//int nuber_of_desks;
	//double speed;
	//data types
	//char(x8),short(x16),int(x32),long int(x32),long long(x64) - integer with a mark
	//float(x32),double(x64)-not integer numbers
	//char- sybols
	//bool,long bool
	std::cout << '\n';
	std::cout << '\n';
	std::cout << "name\t\t|size of \t|min\t\t\t|max\t\n";
	std::cout << "bool \t\t|" << sizeof(bool) << "\t\t|" << 0;
	std::cout << "\t\t\t|" << 0b10000000 << "\t\n";
	std::cout << "int\t\t|" << sizeof(int) << "\t\t|" << INT_MIN;
	std::cout << "\t\t| " << INT_MAX << "\t\n";
	std::cout << "char\t\t|" << sizeof(char) << "\t\t|" << CHAR_MIN;
	std::cout << "\t\t\t| " << CHAR_MAX << "\t\n";
	std::cout << "short\t\t|" << sizeof(short) << "\t\t|" << SHRT_MIN;
	std::cout << "\t\t\t| " << SHRT_MAX << "\t\n";
	std::cout << "long\t\t|" << sizeof(long) << "\t\t|" << LONG_MIN;
	std::cout << "\t\t| " << LONG_MAX << "\t\n";
	std::cout << "double\t\t|" << sizeof(double) << "\t\t|" << DBL_MIN;
	std::cout << "\t\t| " << DBL_MAX << "\t\n";
	std::cout << "long long\t|" << sizeof(long long) << "\t\t|" << LLONG_MIN;
	std::cout << "\t| " << LLONG_MAX << "\t\n";
}