#pragma once
#include <string>

class my_line
{
public:
	my_line();
	~my_line();
	my_line(char * arr);
	my_line(my_line &arr);
	my_line(std::string * arr);
	void clear();
	void add(char * arr);
	void add(std::string arr);
	int insert(int pos, char * arr);
	int insert(int pos, std::string arr);
	int cut(int pos, int num);
	int find(char * lin);
	friend my_line operator + (my_line l1, my_line l2);
	friend std::ostream & operator << (std::ostream & os, my_line & r);
private:
	char * line = nullptr;
	int len;
};