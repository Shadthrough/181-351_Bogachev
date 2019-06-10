#pragma once

#include <QObject>
#include <openssl/conf.h> 
#include <openssl/evp.h>
#include <openssl/err.h>
#include <openssl/aes.h>
#include <qdebug.h>

class AES
{
public:
	AES();
	~AES();
	QByteArray encryptAES(QByteArray &data);
	//QByteArray randomBytes(int size);
	QByteArray decryptAES(QByteArray &data);

};
