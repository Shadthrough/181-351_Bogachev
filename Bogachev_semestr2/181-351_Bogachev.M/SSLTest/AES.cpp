#include "AES.h"

AES::AES()
{
}

AES::~AES()
{
}

/*QByteArray AES::randomBytes(int size) {
	unsigned char arr[size];
	RAND_bytes(arr, size);

	QByteArray buffer = QByteArray(reinterpret_cast<char*>(arr), size);
	return buffer;
}*/

QByteArray AES::encryptAES(QByteArray &data) {

	int round = 1;
	unsigned char* key = (unsigned char *)"0123456789"; 
	unsigned char* iv= (unsigned char *)"0123456789012345"; 


	EVP_CIPHER_CTX *en;
	en = EVP_CIPHER_CTX_new();
	// EVP_CIPHER_CTX_init(&en); 
	EVP_EncryptInit_ex(en, EVP_aes_256_cbc(), NULL, key, iv);

	char *input = data.data();
	char *out;
	int len = data.size();

	int c_len = len + AES_BLOCK_SIZE, f_len = 0;
	unsigned char *ciphertext = (unsigned char*)malloc(c_len);

	
	EVP_EncryptUpdate(en, ciphertext, &c_len, (unsigned char*)input, len);
	EVP_EncryptFinal(en, ciphertext + c_len, &f_len);
	len = c_len + f_len;
	out = (char*)ciphertext;
	EVP_CIPHER_CTX_cipher(en);

	QByteArray encrypted = QByteArray(reinterpret_cast<char*>(ciphertext), len);
	QByteArray finished;

	finished.append(encrypted);
	free(ciphertext);
	return finished;
}

QByteArray AES::decryptAES(QByteArray &data) {

	int round = 1;
	unsigned char* key = (unsigned char *)"0123456789"; 
	unsigned char *iv = (unsigned char *)"0123456789012345"; 


	EVP_CIPHER_CTX *de;
	de = EVP_CIPHER_CTX_new();

	EVP_DecryptInit_ex(de, EVP_aes_256_cbc(), NULL, key, iv);
	char *input = data.data();
	char *out;
	int len = data.size();

	int p_len = len, f_len = 0;
	unsigned char *plaintext = (unsigned char*)malloc(p_len + AES_BLOCK_SIZE);
	EVP_DecryptUpdate(de, plaintext, &p_len, (unsigned char*)input, len);
	EVP_DecryptFinal(de, plaintext + p_len, &f_len);
	len = p_len + f_len;
	out = (char*)plaintext;
	EVP_CIPHER_CTX_cleanup(de);
	QByteArray decrypted = QByteArray(reinterpret_cast<char*>(plaintext), len);
	free(plaintext);
	return decrypted;

}
