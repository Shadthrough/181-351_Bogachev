#pragma once
#include <iostream>
#include <string>
#include <openssl/conf.h> 
#include <openssl/conf.h> 
#include <openssl/evp.h> 
#include <openssl/err.h> 
#include <openssl/aes.h>
#include <fstream>

using namespace std;
class DBClass
{
private:
	std::string first_name[255];
	std::string second_name[255];
	std::string passport[255];
	int num = 0;
public:
	DBClass();
	~DBClass();
	int load(const char * filename, const char * key);
};

