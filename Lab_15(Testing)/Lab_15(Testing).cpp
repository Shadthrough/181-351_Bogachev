//Use std::copy (source_iterator_start, source_iterator_end, destenation) as a way to convert sring to char *;
// If inclide does not work check if using <> instead of "";

#ifdef _MSC_VER
#define _CRT_SECURE_NO_WARNINGS
#endif
#include <iostream>
#include <string>
#include "my_line.h"


int main()
{
	my_line t1;
	my_line t2((char *)"Kill me, I beg u");
	std::string a_line;
	a_line = "Hello, handsome";
	my_line t3(&a_line);
	my_line t4(t2);
	t4.clear();
	t2.add((char*)" I want t die");
	t4.add(a_line);
	t1.add((char*)"Podushka is very soft");
	t1.insert(7, a_line);
	t1.insert(7, (char*)"Testing");
	t1.cut(7, 3);
	std::cout << t3;
	t3.find((char *)"had");
	t4 = (t3 + t1);
	std::cout << t4;
	//*/

		//Testing 
	/*
	std::string line;
	char * lol = (char *)"zalupa";
	line = std::string(lol);
	std::cout << line;*/
	getchar();
	return 0;
}