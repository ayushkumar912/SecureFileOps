#include "main.h"

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
    std::string encryptKey;
    std::cout << "Enter the secret key for encryption (8 characters): ";
    std::getline(std::cin, encryptKey);

    if (encryptKey.length() != 8) {
        std::cerr << "Error: Encryption key must be exactly 8 characters long." << std::endl;
        return 1;
    }

    encryptFile(originalFile, encryptedFile, encryptKey.c_str());

    std::string decryptKey;
    std::cout << "Enter the secret key for decryption (8 characters): ";
    std::getline(std::cin, decryptKey);

    if (decryptKey.length() != 8) {
        std::cerr << "Error: Decryption key must be exactly 8 characters long." << std::endl;
        return 1;
    }

    decryptFile(encryptedFile, decryptedFile, decryptKey.c_str());

    unsigned char decryptedHash[SHA256_DIGEST_LENGTH];
    computeFileHash(decryptedFile, decryptedHash);
    std::cout << "Decrypted file hash: ";
    for (int i = 0; i < SHA256_DIGEST_LENGTH; ++i) {
        std::cout << std::hex << std::setw(2) << std::setfill('0') << (int)decryptedHash[i];
    }
    std::cout << std::endl;

    if (verifyIntegrity(originalHash, decryptedHash)) {
        std::cout << "Integrity verified." << std::endl;
    } else {
        std::cout << "Integrity verification failed." << std::endl;
    }

    return 0;
}
