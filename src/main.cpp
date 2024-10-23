#include "main.h"
#include <iostream>
#include <iomanip>  // For std::setw and std::setfill
#include <cstring>  // For strlen

int main() {
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

    // Get the encryption key from the user
    std::string encryptKey;
    std::cout << "Enter the secret key for encryption (8 characters): ";
    std::getline(std::cin, encryptKey);

    // Ensure the encryption key length is valid
    if (encryptKey.length() != 8) {
        std::cerr << "Error: Encryption key must be exactly 8 characters long." << std::endl;
        return 1;
    }

    // Encrypt the original file
    encryptFile(originalFile, encryptedFile, encryptKey.c_str());

    // Get the decryption key from the user
    std::string decryptKey;
    std::cout << "Enter the secret key for decryption (8 characters): ";
    std::getline(std::cin, decryptKey);

    // Ensure the decryption key length is valid
    if (decryptKey.length() != 8) {
        std::cerr << "Error: Decryption key must be exactly 8 characters long." << std::endl;
        return 1;
    }

    // Decrypt the file
    decryptFile(encryptedFile, decryptedFile, decryptKey.c_str());

    unsigned char decryptedHash[SHA256_DIGEST_LENGTH];
    computeFileHash(decryptedFile, decryptedHash);
    std::cout << "Decrypted file hash: ";
    for (int i = 0; i < SHA256_DIGEST_LENGTH; ++i) {
        std::cout << std::hex << std::setw(2) << std::setfill('0') << (int)decryptedHash[i];
    }
    std::cout << std::endl;

    // Verify the integrity of the decrypted file
    if (verifyIntegrity(originalHash, decryptedHash)) {
        std::cout << "Integrity verified." << std::endl;
    } else {
        std::cout << "Integrity verification failed." << std::endl;
    }

    return 0;
}
