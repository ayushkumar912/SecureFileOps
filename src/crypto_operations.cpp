#include "crypto_operations.h"

void encryptFile(const char* inputFile, const char* outputFile, const char* secretKey) {
    DES_cblock key;
    DES_key_schedule schedule;
    DES_cblock iv;
    DES_string_to_key(secretKey, &key); 
    DES_set_key_checked(&key, &schedule);
    memset(iv, 0, sizeof(iv));

    std::ifstream infile(inputFile, std::ios::binary);
    std::ofstream outfile(outputFile, std::ios::binary);
    char input[8], output[8];

    while (infile.read(input, sizeof(input))) {
        DES_ncbc_encrypt((unsigned char*)input, (unsigned char*)output, sizeof(input), &schedule, &iv, DES_ENCRYPT);
        outfile.write(output, sizeof(output));
    }

    if (infile.gcount() > 0) {
        int remainingBytes = infile.gcount();
        memset(input + remainingBytes, 0, sizeof(input) - remainingBytes);
        DES_ncbc_encrypt((unsigned char*)input, (unsigned char*)output, sizeof(input), &schedule, &iv, DES_ENCRYPT);
        outfile.write(output, sizeof(output));
    }
}

void decryptFile(const char* inputFile, const char* outputFile, const char* secretKey) {
    DES_cblock key;
    DES_key_schedule schedule;
    DES_cblock iv;
    DES_string_to_key(secretKey, &key); 
    DES_set_key_checked(&key, &schedule);
    memset(iv, 0, sizeof(iv));

    std::ifstream infile(inputFile, std::ios::binary);
    std::ofstream outfile(outputFile, std::ios::binary);
    char input[8], output[8];

    while (infile.read(input, sizeof(input))) {
        DES_ncbc_encrypt((unsigned char*)input, (unsigned char*)output, sizeof(input), &schedule, &iv, DES_DECRYPT);
        outfile.write(output, sizeof(output));
    }
    if (infile.gcount() > 0) {
        DES_ncbc_encrypt((unsigned char*)input, (unsigned char*)output, sizeof(input), &schedule, &iv, DES_DECRYPT);
        outfile.write(output, sizeof(output));
    }
}
