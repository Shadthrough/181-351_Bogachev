// Test.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include "pch.h"
#include <iostream>
#include <string>

int main()
{
	//QString temp;
	std::string str = "Zalupa:Krendel,Penis:malenkiy";
	std::string tmp;
	//bdata a;
	std::string::size_type b, e;
	b = str.find(':');
	e = str.find(',');
	tmp = str.substr(b + 1, e-b-1);
	//temp = QString::fromUtf8(tmp.c_str());
	//a.ride = temp;
	std::cout << tmp << std::endl;
	str.erase(0, e);
	b = str.find(':');
	e = str.find(',');
	tmp = str.substr(b + 1, e - b - 1);
	//a.ride = temp;
	std::cout << tmp << std::endl;
}

