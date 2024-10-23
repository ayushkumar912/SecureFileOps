#ifndef CRYPTO_OPERATIONS_H
#define CRYPTO_OPERATIONS_H
#include <openssl/des.h>
#include <cstring>
#include <iostream>
#include <fstream>
void encryptFile(const char *inputFile, const char *outputFile);
void decryptFile(const char *inputFile, const char *outputFile);

#endif
