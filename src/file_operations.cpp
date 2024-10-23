#include "file_operations.h"

void createFile(const char* filename, size_t size) {
    std::ofstream outfile(filename, std::ios::binary);
    if (!outfile) {
        std::cerr << "Failed to create the file: " << filename << std::endl;
        return;
    }
    const char* pattern = "A,b,c,d"; 
    size_t patternLength = strlen(pattern);

    while (size > 0) {
        size_t toWrite = (size < patternLength) ? size : patternLength;
        outfile.write(pattern, toWrite);
        size -= toWrite;
    }

    outfile.close();
}
