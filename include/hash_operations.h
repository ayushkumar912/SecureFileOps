#ifndef HASH_OPERATIONS_H
#define HASH_OPERATIONS_H
#include <openssl/sha.h> 
#include <fstream>
#include <cstring>
void computeFileHash(const char *filename, unsigned char *hash);
bool verifyIntegrity(const unsigned char *originalHash, const unsigned char *decryptedHash);

#endif
