<div align="center">


## 🔐 RC4 File Encryptor & Decryptor

[![Made with C++](https://img.shields.io/badge/Made%20with-C%2B%2B-00599C?style=for-the-badge&logo=c%2B%2B&logoColor=white)](https://isocpp.org/)
[![License: MIT](https://img.shields.io/badge/License-MIT-yellow.svg?style=for-the-badge)](https://opensource.org/licenses/MIT)
[![PRs Welcome](https://img.shields.io/badge/PRs-welcome-brightgreen.svg?style=for-the-badge)](http://makeapullrequest.com)
[![Educational](https://img.shields.io/badge/Purpose-Educational-blueviolet?style=for-the-badge)](https://github.com)

> **A modern C++ implementation of the RC4 stream cipher for file encryption and decryption.**  
> *Built for educational purposes and authorized security training.*

</div>

---


## 📖 Overview

 provides two command-line tools that demonstrate the **RC4 stream cipher** by encrypting and decrypting files. This project is designed for students and security enthusiasts to understand how symmetric stream ciphers work in practice.

| Tool | Description |
|------|-------------|
| **`rc4_encryptor`** | 🔒 Encrypts any file using RC4 with a specified key |
| **`rc4_decryptor`** | 🔓 Decrypts files encrypted with RC4 using the same key |

---

##  Features

| Feature | Description |
|---------|-------------|
|  **Full RC4 Implementation** | KSA + PRGA with proper byte-wise encryption |
|  **Any File Support** | Works with text, binary, images, and more |
|  **Beautiful CLI Output** | Colored tables, hex dumps, and progress indicators |
|  **Readability Check** | Automatically detects if decryption key is wrong |
|  **Hex Preview** | Shows encrypted data in hexadecimal format |
|  **Cross-Platform** | Works on Linux, macOS, and Windows |
|  **Educational Focus** | Clean, well-documented code for learning |

---

## 📸 Screenshot


### Encryption Output


<img width="1485" height="751" alt="Screenshot From 2026-08-29 06-51-53" src="https://github.com/user-attachments/assets/7b29f007-764b-4a47-9ca6-d3b7dcf90d61" />


### Decryption Output
<img width="1200" height="847" alt="Screenshot From 2026-08-29 07-16-52" src="https://github.com/user-attachments/assets/85e68852-b6f5-48db-bcec-850893c9232c" />



---

## 🚀 Quick Start

### Prerequisites

- **C++17 compiler** (GCC 7+, Clang 5+, or MSVC 2017+)
- **No external dependencies** – uses only the standard library

### Installation

```bash
# Clone the repository
git clone https://github.com/yourusername/rc4-encryptor.git
cd rc4-encryptor

# Compile
make          # or: g++ -std=c++17 -o rc4_encryptor rc4_encryptor.cpp
make decrypt  # or: g++ -std=c++17 -o rc4_decryptor rc4_decryptor.cpp

# Run
./rc4_encryptor test1.txt "dere123"
./rc4_decryptor test1.txt "dere123" restored.txt
