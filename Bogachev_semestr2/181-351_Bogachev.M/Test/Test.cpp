// Test.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include "pch.h"
#include <iostream>
#include <string>
#include <fstream>

int main()
{
	std::string a = "aaavd|sava";
	std::cout << a.substr(0, a.find('|'));
	
}

