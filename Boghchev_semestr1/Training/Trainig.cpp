#include <iostream>

class user_data
{
private:
	char first_name[255];
	char last_name[255];
	char passport[10];
public:
	user_data(); // Constructor
	user_data(char p_firstname[255], char p_lastname[255], char p_passport[11]);
	user_data(char p_firstname[255], char p_lastname[255]);
	~user_data(); // Destructor

	bool set_first_name(char p_firstname[255])
	{
		//Check if there is no numbers dots and other synt sumbols exept '-'
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
			first_name[i] = p_firstname[i];
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
			last_name[i] = p_lastname[i];
		}
		return true;
	};
	bool set_passport(char p_passport[10])
	{
		for (int i = 0; i < 10; i++)
		{
			if ((p_passport[i] >= '0') && (p_passport[i] <= '9'))
			{
				passport[i] = p_passport[i];
			}
			else
			{
				return false;
			}
		}
		return true;
	}
};
user_data::user_data()
{

}
user_data::~user_data()
{

}
user_data::user_data(char p_firstname[255], char p_lastname[255], char p_passport[11])
{
	for (int i = 0; i < 255; i++)
	{
		first_name[i] = p_firstname[i];
		last_name[i] = p_lastname[i];
	}
	for (int i = 0; i < 10; i++)
	{
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
	char a[] = "Anton";
	char b[] = "Veronkin";
	char d[] = "1234567890";
	char a1[] = "Petrov";
	char b1[] = "Petr";
	user_data user1;
	user_data user2(a, b, d);
	user_data user3(a1, b1);
	user2.set_first_name(a);
	return 0;
}