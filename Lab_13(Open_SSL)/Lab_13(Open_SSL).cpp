#ifdef _MSC_VER
#define _CRT_SECURE_NO_WARNINGS
#endif
#include <iostream>
#include <openssl/conf.h> // �������, ��������� � ��������� ��������� OpenSSL
#include <openssl/conf.h>
#include <openssl/evp.h> // ���� ���������������� ������� https://wiki.openssl.org/index.php/EVP
#include <openssl/err.h> // ���� ���������� ������ OpenSSL � �� �����������
#include <openssl/aes.h>
#include <fstream>
#include <string>
#include <cstring>

#pragma comment (lib, "ws2_32.LIB")
#pragma comment (lib, "gdi32.LIB")
#pragma comment (lib, "advapi32.LIB")
#pragma comment (lib, "crypt32")
#pragma comment (lib, "user32")
#pragma comment (lib, "wldap32")

//#define BUFLEN 256
// ���������� OpenSSL (openssl.org) ������������ ������ ����������� (��. �������� ���. �� �����������)

using namespace std;

int main()
{
	// ������ � ��������������� OpenSSL:
	// 1) �������� ������� � �����������
	// 2) ����������, ����������
	// 3) �����������
	// 4) � ����� ������������� ������

	// ��� �������, � ����������, ��������� ������������ ��� �������� ������ ������
	// �� ����� � ������� � �������������/������������
	struct name_of_my_struct // ������ ������
	{
		name_of_my_struct()
		{

		}

		int a;
		double b;
		int fnc1()
		{
			return a;
		}
	};
	FILE *in, *out;
	in = fopen("in.txt", "r");
	unsigned char plaintext[256];
	int plaintext_len;// = fread(plaintext, 1, BUFLEN, in); // ����� ������
	unsigned char *key = (unsigned char *)"0123456789"; // ������ (����)
	unsigned char *iv = (unsigned char *)"0123456789012345"; // ���������������� ������, �����������
	unsigned char cryptedtext[256]; // ������������� ���������
	unsigned char decryptedtext[256]; // �������������� ���������

	// 1. �������� ��������� �� �������������� ���������
	// ��������� - ��� ������ � C++, ������ � ������, �������� ����������
	EVP_CIPHER_CTX *ctx; // structure

	// 2. ��� ��������� �������� ������ ��������� �������� (�����, ����, ������ ������������� � �.�.)
	ctx = EVP_CIPHER_CTX_new(); // �������� ��������� � ����������� ������

	// 3. ��������� EVP_CIPHER_CTX ����������� �����������
	EVP_EncryptInit_ex(ctx, // ������ �� ������/���������, ���� ��������� ���������
		EVP_aes_256_cbc(), // ������ �� ��������� ���� AES 256 (������� � ����������)
		NULL,
		key, // ����/������/������
		iv); // ����������� (��������� ��������� ������)

	// 4. ��� ������� ���������� - ������� EVP_EncryptUpdate
	int len;
	out = fopen("out.txt", "w");
	for (;;)
	{
		plaintext_len = fread(plaintext, 1, 256, in);
		if (plaintext_len <= 0) break;
		if (!EVP_EncryptUpdate(ctx, // ������ � �����������
			cryptedtext, // ������� ��������: ������, ���� �������� ������������� ������
			&len, // �������� ��������: ����� ����������� �����
			plaintext, // ������� ��������: ��� ���������
			plaintext_len)) return 0; // ������� �������� : ����� ������� ������
		fwrite(cryptedtext, 1, len, out);
	}
	int cryptedtext_len = len;

	// 5. ����������� �������� ����������
	// ����������, ���� ��������� ���� �������� ������� �� ���������
	EVP_EncryptFinal_ex(ctx, cryptedtext + len, &len);
	cryptedtext_len += len;
	fwrite(cryptedtext, 1, cryptedtext_len, out);

	// 6. �������� ���������
	EVP_CIPHER_CTX_free(ctx);
	fclose(in);
	fclose(out);

	// ����� ������������� ������
	for (int i = 0; i < cryptedtext_len; i++)
	{
		cout << hex << cryptedtext[i];
		if ((i + 1) % 32 == 0) cout << endl;
	}
	cout << endl;

	// �����������

	// 1.
	ctx = EVP_CIPHER_CTX_new(); // �������� ��������� � ����������� ������

	// 2.
	EVP_DecryptInit_ex(ctx, EVP_aes_256_cbc(), NULL, key, iv); // ������������� ������� AES, ������ � ��������

	// 3.
	EVP_DecryptUpdate(ctx, decryptedtext, &len, cryptedtext, cryptedtext_len);  // ����������, ����������

	// 4.
	int dectypted_len = len;
	EVP_DecryptFinal_ex(ctx, decryptedtext + len, &len);

	// 5.
	dectypted_len += len;
	EVP_CIPHER_CTX_free(ctx);
	decryptedtext[dectypted_len] = '\0';
	cout << decryptedtext << endl;

	// --- ���������� �����
	// ������������ ����� ��� ��, �� ��������, � �����
	// � �����
	/*
		1) �������� ������ � ��������� ���������� OpenSSL
		2) ���������� ������� �����
		3) while(���������_�������� > 0)
		{
			4) ���������� ����������
			5) ������ �������������� ������� � ����
			6) ���������� ���������� ���������
		}
		7) ���������� �������������� �������
		8) ������ ��������������� ����� � ����
		9) �������� ������
	*/
	getchar();
	return 0;
}