#include "DBClass.h"


DBClass::DBClass()
{
}


DBClass::~DBClass()
{
}

int DBClass::load(const char * filename, const char * key)
{
	EVP_CIPHER_CTX *ctx;
	ctx = EVP_CIPHER_CTX_new(); // conf struct
	ifstream infile;
	char buffer[256];
	char buffer1[256];
	unsigned char *iv = (unsigned char *)"0123456789012345";
	// 2.
	EVP_DecryptInit_ex(ctx, EVP_aes_256_cbc(), NULL, (const unsigned char*)key, iv); // init with AES key & vector

	// 3.
	infile.open(filename, fstream::in | fstream::binary);
	while (!infile.eof())
	{
		infile.getline(buffer, 256);
		int cryptedtext_len = 256;
		int len = sizeof(buffer);
		EVP_DecryptUpdate(ctx, (unsigned char*)buffer1, &len, (unsigned char*)buffer, cryptedtext_len);// decryption

		// 4.
		int dectypted_len = len;
		EVP_DecryptFinal_ex(ctx, (unsigned char*)buffer1, &len);//+len

		// 5.
		dectypted_len += len;
		EVP_CIPHER_CTX_free(ctx);
		string a(buffer1);
		if (a.find("Name") != -1)
		{
			for (int i = a.find("Name") + 7; i < a.length(); i++)
			{
				if (a[i] == '/"')
				{
					break;
				}
				first_name[num] += a[i];

			}

		}
		else if (a.find("Second name") != -1)
		{
			for (int i = a.find("Second name") + 13; i < a.length(); i++)
			{
				if (a[i] == '/"')
				{
					break;
				}
				second_name[num] += a[i];//переменная для фамилии

			}
		}
		else if (a.find("Passport") != -1)
		{
			for (int i = a.find("Passport") + 10; i < a.length(); i++)
			{
				if (a[i] == '/"')
				{
					break;
				}
				passport[num] += a[i];//переменная для паспорта


			}

		}
		else if (a.find("}") != -1)
		{
			num += 1;
		}
	}

	return 0;
}
