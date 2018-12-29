//#ifdef _MSC_VER
//#define _CRT_SECURE_NO_WARNINGS
//#endif
#include <iostream>
#include <string>
#include <cstring>
#include "my_line.h"

my_line operator+(my_line l1, my_line l2)
{
	my_line temp;
	temp.len = l1.len + l2.len;
	temp.line = new char[temp.len];
	temp.add(l1.line);
	temp.add(l2.line);
	return temp;
}

std::ostream & operator << (std::ostream & os, my_line & r)
{
	os << r.line << "\t<< operator succ\n";
	return os;
}

int my_line::find(char * lin)
{
	std::string temp = std::string(line);
	if (temp.find(lin, len) != std::string::npos)
	{
		std::cout << "Match found\n";
		return 0;
	}
	else
	{
		std::cout << "Match not found\n";
		return 0;
	}
}

void my_line::clear()
{
	line = nullptr;
	len = 0;
	delete[] line;
	//std::cout << "Cleared line\n" << line;
}

int my_line::cut(int pos, int num)
{
	if (pos + num <= len)
	{
		len -= num;
		std::string temp;
		temp = std::string(line);
		temp.erase(pos, num);
		line = nullptr;
		delete[] line;
		line = new char[len];
		std::copy(temp.begin(), temp.end(), line);
		line[len] = '\0';
		std::cout << "Cut succ\n" << line << std::endl;
		return 0;
	}
	return -1;
}

int my_line::insert(int pos, char * arr) // inserting  char
{
	if (pos <= len)
	{
		len += strlen(arr);
		std::string temp;
		temp = line;
		temp.insert(pos, arr);
		line = nullptr;
		delete[] line;
		line = new char[len];
		std::copy(temp.begin(), temp.end(), line);
		line[len] = '\0';
		std::cout << "Char insert succ\n" << line << std::endl;
		return 0;
	}
	return -1;
}

int my_line::insert(int pos, std::string arr) // inserting a string
{
	if (pos <= len)
	{
		len += arr.length();
		std::string temp;
		temp = line;
		temp.insert(pos, arr);
		line = nullptr;
		delete[] line;
		line = new char[len];
		std::copy(temp.begin(), temp.end(), line);
		line[len] = '\0';
		std::cout << "String insert succ\n" << line << std::endl;
		return 0;
	}
	return -1;
}

void my_line::add(char * arr)
{
	len += strlen(arr);
	/*char * temp = new char[len];
	temp = line;
	temp = strcat(temp, arr);
	line = nullptr;
	delete[] line;
	line = new char[len];
	line = temp;
	std::cout << "Char add succ\n" << line << std::endl;
	delete[] temp;
	*/
	std::string temp1, temp2;
	if (line != nullptr) temp1 = std::string(line);
	temp2 = std::string(arr);
	temp1.append(temp2);
	line = nullptr;
	delete[] line;
	line = new char[len];
	std::copy(temp1.begin(), temp1.end(), line);
	line[len] = '\0';
	std::cout << "Char add succ\n" << line << std::endl;
}

void my_line::add(std::string arr)
{
	len += arr.length();
	std::string temp;
	if (line != nullptr) temp = std::string(line);
	temp.append(arr);
	line = nullptr;
	delete[] line;
	line = new char[len];
	std::copy(temp.begin(), temp.end(), line);
	line[len] = '\0';
	std::cout << "String add succ\n" << line << std::endl;
}

my_line::my_line()
{
}

my_line::my_line(char * arr)
{
	line = arr;
	len = strlen(arr);
	std::cout << "Char constr succ\n" << line << std::endl;
}

my_line::my_line(my_line &arr)
{
	len = arr.len;
	line = arr.line;
	std::cout << "Class constr succ\n" << line << std::endl;
}

my_line::my_line(std::string * arr)
{
	len = arr->length();
	line = new char[arr->size() + 1];
	std::copy(arr->begin(), arr->end(), line);
	//strcpy_s(line, arr->length(), (char*)arr);
	line[arr->size()] = '\0';
	std::cout << "Sring constr succ\n" << line << std::endl;
	//delete[] line;
}

my_line::~my_line()
{
}
