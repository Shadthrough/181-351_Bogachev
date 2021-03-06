/*
1. Class's functions are all it's varyibles
2. Method - functions in the class
3. Incapsulation - uniting into a single system
4. Inharitance - taking all properties from an elder class
5. Polymophizm - elements of a single class may behave diffirently
*/
#include "pch.h"
#include <iostream>
																	/*class vehicle
{
private: //Access granted only to the programmer (methods of it's class can call it)
public: // Access can be granted from anywhere (main; methods; from th outside,
		//where the object is seen)
	double speed;
	char regnumber[6] = { 0 }; //Gosnumber
	unsigned char capacity; //numb of passengers
	bool check_regnumber()
	{

	}
	// void add_passenger (int passenger)
};																	*/
// 2. Syntacsis for calling to properties and methods
// Class name = obj name;
// vehicle car;
// car.speed = 123;
// car.add_passenger(value)

// 3. Access properties
// Private; Public; Protected;

// 4. Constr, Deconstr.

// 5. Sructures = Class without privacy


class user_data
{
private:	
	char first_name[255];
	char last_name[255];
	char passport[10];
	char birthdate[10];
public:
	user_data(); // Constructor
	user_data(char p_firstname[255], char p_lastname[255], char p_birthdate[11], char p_passport[11]);
	user_data(char p_firstname[255], char p_lastname[255]);
	~user_data(); // Destructor

	bool set_first_name(char p_firstname[255])
	{
		//Check if there is no numbers dots and other synt sumbols exept '-'
		bool check;
		for (int i = 0; i < '\0'; i++)
		{
			if (((p_firstname[i] >= 33) && (p_firstname[i] <= 44)) || 
				((p_firstname[i] >= 46) && (p_firstname[i] <= 64)))
			{
				return false;
			}
			if ((p_firstname[i] >= 91) && (p_firstname[i] <= 96))
			{
				return false;
			}
		}
		return true;
	};
	bool set_last_name(char p_lastname[10])
	{
		for (int i = 0; i < '\0'; i++)
		{
			if (((p_lastname[i] >= 33) && (p_lastname[i] <= 44)) ||
				((p_lastname[i] >= 46) && (p_lastname[i] <= 64)))
			{
				return false;
			}
			if ((p_lastname[i] >= 91) && (p_lastname[i] <= 96))
			{
				return false;
			}
		}
		return true;
	};
	bool set_birthdate(char p_birthdate[10])
	{
		//must be like 00.00.0000
		for (int i = 0; i < 10; i++)
		{
			if ((p_birthdate[i] >= '.') && (p_birthdate[i] <= '9'))
			{
				return true;
			}
			else
			{
				return false;
			}
		}
	};
	bool set_passport(char p_passport[10])
	{
		for (int i = 0; i < 10; i++)
		{
			if ((p_passport[i] >= '0') && (p_passport[i] <= '9'))
			{
				return true;
			}
			else
			{
				return false;
			}
		}
	}
};
user_data::user_data()
{

}
user_data::~user_data()
{

}
user_data::user_data(char p_firstname[255], char p_lastname[255], char p_birthdate[11], char p_passport[11])
{
	for (int i = 0; i < 255; i++)
	{
		first_name[i] = p_firstname[i];
		last_name[i] = p_lastname[i];
	}
	for (int i = 0; i < 10; i++)
	{
		birthdate[i] = p_birthdate[i];
		passport[i] = p_passport[i];
	}
}
user_data::user_data(char p_firstname[255], char p_lastname[255])
{
	for (int i = 0; i < 255; i++)
	{
		first_name[i] = p_firstname[i];
		last_name[i] = p_lastname[i];
	}
}

int main()
{
	user_data Person1;
	char firstname[] = "Maksim";
	if (Person1.set_first_name(firstname) == true)
	{
		std::cout << "firstname: Ur good" << std::endl;
	}
	else
	{
		std::cout << "firstname: NO, ur dumb" << std::endl;
	}
	char lastname[] = "Bogachev";
	if (Person1.set_last_name(lastname) == true)
	{
		std::cout << "lastname: Ur good" << std::endl;
	}
	else
	{
		std::cout << "lastname: NO, ur dumb" << std::endl;
	}
	char date[] = "24.02.2000";
	if (Person1.set_birthdate(date) == true)
	{
		std::cout << "date: Ur good" << std::endl;
	}
	else
	{
		std::cout << "date: NO, ur dumb" << std::endl;
	}
	char a[] = "Anton";
	char b[] = "Veronkin";
	char c[] = "24.01.1234";
	char d[] = "1234567890";
	char a1[] = "Petrov";
	char b1[] = "Petr";
	user_data user1;
	user_data user2(a,b,c,d);
	user_data user3(a1,b1);
	user2.set_first_name(a);
	return 0;
}

