
#include "hash_operations.h"

void computeFileHash(const char* filename, unsigned char *hash) { 
    char buffer[4096];
    std::ifstream file(filename, std::ios::binary);
    SHA256_CTX sha256;
    SHA256_Init(&sha256);

    while (file.read(buffer, sizeof(buffer))) {
        SHA256_Update(&sha256, buffer, file.gcount());
    }
    SHA256_Final(hash, &sha256);
}

bool verifyIntegrity(const unsigned char* originalHash, const unsigned char* decryptedHash) {
    return memcmp(originalHash, decryptedHash, SHA256_DIGEST_LENGTH) == 0;
}
