// If can not find error for std funcs do: cout << std::strerror(errno);
// find pic on html, find face, replace with pic, cipher the pic
#ifdef _MSC_VER
#define _CRT_SECURE_NO_WARNINGS
#endif
#include <iostream>
#include <openssl/conf.h> // функции, структуры и константы настройки OpenSSL
#include <openssl/conf.h>
#include <openssl/evp.h> // сами криптогрфические функции https://wiki.openssl.org/index.php/EVP
#include <openssl/err.h> // коды внутренних ошибок OpenSSL и их расшифровка
#include <openssl/aes.h>
#include <fstream>
#define CURL_STATICLIB 
#include "curl/curl.h" 
#include <stdio.h> 
#include <string> 
#include <vector>

#include <opencv2\opencv.hpp>
#include <opencv2\imgproc\types_c.h>
#include <opencv2\imgcodecs.hpp>
#include <opencv2\core.hpp>
#include <opencv2\imgproc.hpp>
#include <opencv2\highgui.hpp>
#include <opencv2\objdetect.hpp>

#ifdef _WIN64 
#pragma comment (lib, "Normaliz.lib") 
#pragma comment (lib, "Ws2_32.lib") 
#pragma comment (lib, "Wldap32.lib") 
#pragma comment (lib, "Crypt32.lib") 
#pragma comment (lib, "advapi32.lib") 
#elif _WIN32 
#pragma comment (lib, "Normaliz.lib") 
#pragma comment (lib, "Ws2_32.lib") 
#pragma comment (lib, "Wldap32.lib") 
#pragma comment (lib, "Crypt32.lib") 
#pragma comment (lib, "advapi32.lib") 
#endif 

#pragma comment (lib, "ws2_32.LIB")
#pragma comment (lib, "gdi32.LIB")
#pragma comment (lib, "advapi32.LIB")
#pragma comment (lib, "crypt32")
#pragma comment (lib, "user32")
#pragma comment (lib, "wldap32")


using namespace std;

static int writer(char *data,
	size_t size,
	size_t nmemb,
	std::string *writerData)
{
	if (writerData == NULL)
		return 0;

	writerData->append(data, size*nmemb);

	return size * nmemb;
}

static char download_data(char *ptr, size_t size, size_t nmemb, FILE* data)
{
	return fwrite(ptr, size, nmemb, data);
}
void download_connect(char*url)
{
	FILE *img_file = fopen("1.jpg", "wb");
	CURL *curl_handle;
	CURLcode res;
	do
	{
		curl_handle = curl_easy_init();
		if (curl_handle)
		{
			curl_easy_setopt(curl_handle, CURLOPT_URL, url);
			curl_easy_setopt(curl_handle, CURLOPT_WRITEDATA, img_file);
			curl_easy_setopt(curl_handle, CURLOPT_WRITEFUNCTION, download_data);
			curl_easy_setopt(curl_handle, CURLOPT_SSL_VERIFYPEER, 0);
			curl_easy_setopt(curl_handle, CURLOPT_FOLLOWLOCATION, 1);
			res = curl_easy_perform(curl_handle);
			curl_easy_cleanup(curl_handle);
		}
	} while (res == CURLE_COULDNT_CONNECT || res == CURLE_COULDNT_RESOLVE_HOST);
	fclose(img_file);
}

int main()
{
	struct name_of_my_struct
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
	char * myurl = (char *)"http://groteck.ru/attachments/news01/90580/2.jpg";
	download_connect(myurl);
			
	/* Инициализация */
	cv::CascadeClassifier face_cascade;
	cv::Mat image = cv::imread("1.jpg");
	cv::Mat groupFaces = cv::Mat(image.rows, image.cols, CV_8UC4);
	cv::cvtColor(image, groupFaces, cv::COLOR_BGR2BGRA);
	//cv::winrt_initContainer(cvContainer);
	cv::imshow(std::string("Window 1"), groupFaces);
	
	if (!face_cascade.load("haarcascade_frontalface_alt.xml")) {
		std::cout << "Couldn't load face detector" << std::endl;
	}

	/* Обнаружение */
	if (!groupFaces.empty()) {
		std::vector<cv::Rect> facesColl;
		cv::Mat frame_gray;

		cvtColor(groupFaces, frame_gray, cv::COLOR_BGR2GRAY);
		cv::equalizeHist(frame_gray, frame_gray);

		// Detect faces
		face_cascade.detectMultiScale(frame_gray,
			facesColl,
			1.1, 2,
			0 | cv::CASCADE_SCALE_IMAGE,
			cv::Size(1, 1));
		for (unsigned int i = 0; i < facesColl.size(); i++)
		{
			auto face = facesColl[i];
			cv::rectangle(groupFaces, face, cv::Scalar(200, 240, 0), 4);
		}

		cv::imshow(std::string("Window 2"), groupFaces);
	}
	else {
		std::cout << "Initialize image before processing" << std::endl;
	}
	/*
	unsigned char *plaintext =
		(unsigned char *)"EVP_EncryptUpdate() encrypts inl bytes from the buffer in and writes the encrypted version to out";// исходный текст
	int plaintext_len = strlen((char *)plaintext); // длина текста
	unsigned char *key = (unsigned char *)"0123456789"; // пароль (ключ)
	unsigned char *iv = (unsigned char *)"0123456789012345"; // инициализирующий вектор, рандомайзер
	unsigned char cryptedtext[256]; // зашифрованный результат
	unsigned char decryptedtext[256]; // расшифрованный результат

	EVP_CIPHER_CTX *ctx; // structure
	ctx = EVP_CIPHER_CTX_new(); // создание структуры с настройками метода
	EVP_EncryptInit_ex(ctx, EVP_aes_256_cbc(), NULL, key, iv); // рандомайзер (случайный начальный вектор)
	int len;
	EVP_EncryptUpdate(ctx, // объект с настройками
		cryptedtext, // входной параметр: ссылка, куда помещать зашифрованные данные
		&len, // выходной параметр: длина полученного шифра
		plaintext, // входной параметр: что шифровать
		plaintext_len); // входной параметр : длина входных данных
	int cryptedtext_len = len;

	EVP_EncryptFinal_ex(ctx, cryptedtext + len, &len);
	cryptedtext_len += len;

	EVP_CIPHER_CTX_free(ctx);

	for (int i = 0; i < cryptedtext_len; i++)
	{
		cout << hex << cryptedtext[i];
		if ((i + 1) % 32 == 0) cout << endl;
	}
	cout << endl;

	// РАСШИФРОВКА

	// 1.
	ctx = EVP_CIPHER_CTX_new(); // создание структуры с настройками метода

	// 2.
	EVP_DecryptInit_ex(ctx, EVP_aes_256_cbc(), NULL, key, iv); // инициализация методом AES, ключом и вектором

	// 3.
	EVP_DecryptUpdate(ctx, decryptedtext, &len, cryptedtext, cryptedtext_len);  // СОБСТВЕННО, ШИФРОВАНИЕ

	// 4.
	int dectypted_len = len;
	EVP_DecryptFinal_ex(ctx, decryptedtext + len, &len);

	// 5.
	dectypted_len += len;
	EVP_CIPHER_CTX_free(ctx);
	decryptedtext[dectypted_len] = '\0';
	cout << decryptedtext << endl;
				*/
	cv::waitKey();
	return 0;
}