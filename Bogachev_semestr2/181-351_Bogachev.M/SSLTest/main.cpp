#include <QtCore/QCoreApplication>
#include <iostream>
#include "AES.h"
#include <qdebug.h>
//#define BUFLEN 256

//using namespace std;

int main(int argc, char *argv[])
{
	QCoreApplication a(argc, argv);
	/*
	FILE *in, *out, *outd;
	in = fopen("in.txt", "rb");
	unsigned char plaintext[256];
	int plaintext_len;// = fread(plaintext, 1, BUFLEN, in); // text length
	unsigned char *key = (unsigned char *)"0123456789"; // password (key)
	unsigned char *iv = (unsigned char *)"0123456789012345"; // initialysing vector, randomizer
	unsigned char cryptedtext[256]; // encrypted result
	unsigned char decryptedtext[256]; // decrypted result

	// 1. The pointer on a carrying structure is created
	EVP_CIPHER_CTX *ctx; // structure

	// 2. Empty sructure of settings is created for the pointer (method, key, init vector etc)
	ctx = EVP_CIPHER_CTX_new(); // creating struct with method's settings

	// 3. structure EVP_CIPHER_CTX filled with settings
	EVP_EncryptInit_ex(ctx, // link on obj/struct to where data is pushed
		EVP_aes_256_cbc(), // link an a crypting kernel AES 256 (func with algorythm)
		NULL,
		key, // password
		iv); // randomizer (random starting vector)

	// 4. actual encryption - FUNC EVP_EncryptUpdate
	int len;
	out = fopen("outcrypt.txt", "wb");
	for (;;)
	{
		plaintext_len = fread(plaintext, 1, 256, in);
		if (plaintext_len <= 0) break;
		if (!EVP_EncryptUpdate(ctx, // obj with settings
			cryptedtext, // out: where will be encrypted data
			&len, // out: encrypted data length
			plaintext, // in: data to be encrypted
			plaintext_len)) return 0; // in: it's length
		fwrite(cryptedtext, 1, len, out);
	}
	int cryptedtext_len = len;

	// 5. finalisation of encryption
	//nessessary if last block of data is not comletely filled
	EVP_EncryptFinal_ex(ctx, cryptedtext, &len);
	cryptedtext_len += len;
	fwrite(cryptedtext, 1, len, out);

	// 6. deleting the structure
	EVP_CIPHER_CTX_free(ctx);
	fclose(in);
	fclose(out);

	// output of encrypted data
	for (int i = 0; i < cryptedtext_len; i++)
	{
		std::cout << hex << cryptedtext[i];
		if ((i + 1) % 32 == 0) std::cout << endl;
	}
	std::cout << endl;

	// decryption

	// 1.
	ctx = EVP_CIPHER_CTX_new(); // conf struct

	// 2.
	EVP_DecryptInit_ex(ctx, EVP_aes_256_cbc(), NULL, key, iv); // init with AES key & vector

	// 3.
	out = fopen("outcrypt.txt", "rb");
	outd = fopen("outdecrypt.txt", "wb");
	for (;;)
	{
		cryptedtext_len = fread(cryptedtext, 1, 256, out);
		if (cryptedtext_len <= 0) break;
		if (!EVP_DecryptUpdate(ctx, decryptedtext, &len, cryptedtext, cryptedtext_len)) return 0;// decryption
		fwrite(decryptedtext, 1, len, outd);

	}
	// 4.
	int dectypted_len = len;
	EVP_DecryptFinal_ex(ctx, decryptedtext, &len);//+len

	// 5.
	dectypted_len += len;
	EVP_CIPHER_CTX_free(ctx);
	decryptedtext[dectypted_len] = '\0';
	fwrite(decryptedtext, 1, len, outd);////////////////////////////////////////////////

	std::cout << decryptedtext << endl;
	fclose(out);
	fclose(outd);
//*/
	//FILE *in, *out, *outd;
	//in = fopen("in.txt", "rb");
	/*
	QByteArray arr = "I have creepling depression";
	QByteArray cryp;
	unsigned char plaintext[256];
	int plaintext_len = 256; // text length
	unsigned char *key = (unsigned char *)"0123456789"; // password (key)
	unsigned char *iv = (unsigned char *)"0123456789"; // initialysing vector, randomizer
	unsigned char cryptedtext[256]; // encrypted result
	unsigned char decryptedtext[256]; // decrypted result
	// 1. The pointer on a carrying structure is created
	EVP_CIPHER_CTX *ctx; // structure
	// 2. Empty sructure of settings is created for the pointer (method, key, init vector etc)
	ctx = EVP_CIPHER_CTX_new(); // creating struct with method's settings
	// 3. structure EVP_CIPHER_CTX filled with settings
	EVP_EncryptInit_ex(ctx, // link on obj/struct to where data is pushed
		EVP_aes_256_cbc(), // link an a crypting kernel AES 256 (func with algorythm)
		NULL,
		key, // password
		iv); // randomizer (random starting vector)
	// 4. actual encryption - FUNC EVP_EncryptUpdate
	int len;
	for (;;)
	{
		for (int i = 0; i < arr.size(); i++)
		{
			if (i == 256)
				break;
			plaintext[i] = arr[i];
		}
		//plaintext = arr.data();
		if (arr.size() >= 256)
			plaintext_len = 256;
		else
			plaintext_len = arr.size();
		if (plaintext_len <= 0) break;
		arr.remove(0, 255);
		if (!EVP_EncryptUpdate(ctx, // obj with settings
			cryptedtext, // out: where will be encrypted data
			&len, // out: encrypted data length
			plaintext, // in: data to be encrypted
			plaintext_len)) return 0; // in: it's length
		//fwrite(cryptedtext, 1, len, out);
		cryp.append(QByteArray(reinterpret_cast<char*>(cryptedtext), len));
	}
	int cryptedtext_len = len;
	// 5. finalisation of encryption
	//nessessary if last block of data is not comletely filled
	EVP_EncryptFinal_ex(ctx, cryptedtext, &len);
	cryptedtext_len += len;
	cryp.append(QByteArray(reinterpret_cast<char*>(cryptedtext), len));
	// 6. deleting the structure
	EVP_CIPHER_CTX_free(ctx);
	// output of encrypted data
	for (int i = 0; i < cryptedtext_len; i++)
	{
		std::cout << hex << cryptedtext[i];
		if ((i + 1) % 32 == 0) std::cout << endl;
	}
	std::cout << endl;
	// decryption
	arr.clear();
	// 1.
	ctx = EVP_CIPHER_CTX_new(); // conf struct

	// 2.
	EVP_DecryptInit_ex(ctx, EVP_aes_256_cbc(), NULL, key, iv); // init with AES key & vector

	// 3.
	
	for (;;)
	{
		for (int i = 0; i < cryp.size(); i++)
		{
			if (i == 256)
				break;
			cryptedtext[i] = arr[i];
		}
		cryptedtext_len = cryp.size();
		cryp.remove(0, 255);
		if (cryptedtext_len <= 0) break;
		if (!EVP_DecryptUpdate(ctx, decryptedtext, &len, cryptedtext, cryptedtext_len)) return 0;// decryption
		arr.append(QByteArray(reinterpret_cast<char*>(decryptedtext), len));

	}
	// 4.
	int dectypted_len = len;
	EVP_DecryptFinal_ex(ctx, decryptedtext, &len);//+len

	// 5.
	dectypted_len += len;
	EVP_CIPHER_CTX_free(ctx);
	decryptedtext[dectypted_len] = '\0';
	arr.append(QByteArray(reinterpret_cast<char*>(decryptedtext), len));////////////////////////////////////////////////

	std::cout << decryptedtext << std::endl << std::endl;

	qDebug() << "Now the array:" << arr;
	//////////////////////////////////////////////////////////////////////////////////////////////
	*/
	QByteArray arr = "YA DUraChekYA";
	AES crup;
	QByteArray cr = crup.encryptAES(arr);
	qDebug() << cr;
	arr = crup.decryptAES(cr);
	qDebug() << arr;
	//*/

	return a.exec();
}