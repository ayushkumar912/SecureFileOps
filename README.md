# SecureFileOps

**SecureFileOps** is a C++ project that provides secure file operations, including encryption, decryption, and integrity verification using SHA-256 hashing. This tool is designed to help you manage sensitive data by ensuring that files are securely encrypted and can be verified for integrity.

## Features

- **File Creation**: Generate files of specified sizes filled with data.
- **Encryption**: Secure files using DES encryption.
- **Decryption**: Retrieve original files from encrypted versions.
- **Integrity Verification**: Check if the decrypted file matches the original file using SHA-256 hashing.

## Requirements

- C++11 or later
- OpenSSL 3.x
- A compatible compiler (e.g., g++, clang++)

## Installation

1. Clone the repository:
   ```bash
   git clone https://github.com/ayushkumar912/SecureFileOps.git
   cd SecureFileOps
   ```

2. Install OpenSSL via Homebrew (if not already installed):
   ```bash
   brew install openssl@3
   ```

3. Build the project:
   ```bash
   make
   ```

## Usage

1. Create a file:
   - The project creates a 4KB file named `testfile.txt` in the `data` directory.

2. Run the program:
   ```bash
   ./project
   ```

3. The program will:
   - Display the hash of the original file.
   - Encrypt the original file and save it as `encrypted.bin`.
   - Decrypt the encrypted file and save it as `decrypted.txt`.
   - Display the hash of the decrypted file.
   - Verify the integrity of the decrypted file against the original file.

## Example Output

```
Original file hash: 6896d9ea3f73a4434f5832bc65714e7d066f177373f36f34dc8a6f735daa41b1
Decrypted file hash: 6896d9ea3f73a4434f5832bc65714e7d066f177373f36f34dc8a6f735daa41b1
Integrity verified.
```

## Contributing

Contributions are welcome! Please fork the repository and submit a pull request.

## License

This project is licensed under the Apache License. See the [LICENSE](LICENSE) file for details.

## Acknowledgments

- [OpenSSL](https://www.openssl.org/) for the cryptographic library.
- Any other libraries or resources you used.
# SecureFileOps
