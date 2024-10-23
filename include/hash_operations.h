#ifndef HASH_OPERATIONS_H
#define HASH_OPERATIONS_H
#include <openssl/sha.h> 
void computeFileHash(const char *filename, unsigned char *hash);
bool verifyIntegrity(const unsigned char *originalHash, const unsigned char *decryptedHash);

#endif
