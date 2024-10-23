#include <iostream>
#include <iomanip>
#include <openssl/sha.h>
#include "file_operations.h"
#include "crypto_operations.h"
#include "hash_operations.h"

int main()
{
    const char *originalFile = "data/testfile.txt";
    const char *encryptedFile = "data/encrypted.bin";
    const char *decryptedFile = "data/decrypted.txt";
    createFile(originalFile, 4096);

    unsigned char originalHash[SHA256_DIGEST_LENGTH];
    computeFileHash(originalFile, originalHash); 
    std::cout << "Original file hash: ";
    for (int i = 0; i < SHA256_DIGEST_LENGTH; ++i) {
        std::cout << std::hex << std::setw(2) << std::setfill('0') << (int)originalHash[i];
    }
    std::cout << std::endl;

    encryptFile(originalFile, encryptedFile);

    decryptFile(encryptedFile, decryptedFile);

    unsigned char decryptedHash[SHA256_DIGEST_LENGTH];
    computeFileHash(decryptedFile, decryptedHash);
    std::cout << "Decrypted file hash: ";
    for (int i = 0; i < SHA256_DIGEST_LENGTH; ++i) {
        std::cout << std::hex << std::setw(2) << std::setfill('0') << (int)decryptedHash[i];
    }
    std::cout << std::endl;

    if (verifyIntegrity(originalHash, decryptedHash)) 
    {
        std::cout << "Integrity verified." << std::endl;
    }
    else
    {
        std::cout << "Integrity verification failed." << std::endl;
    }

    return 0;
}
