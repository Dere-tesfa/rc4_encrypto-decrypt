<div align="center">

# 🔐 RC4 File Encryptor & Decryptor

[![Made with C++](https://img.shields.io/badge/Made%20with-C%2B%2B-00599C?style=for-the-badge&logo=c%2B%2B&logoColor=white)](https://isocpp.org/)
[![License: MIT](https://img.shields.io/badge/License-MIT-yellow.svg?style=for-the-badge)](https://opensource.org/licenses/MIT)
[![PRs Welcome](https://img.shields.io/badge/PRs-welcome-brightgreen.svg?style=for-the-badge)](http://makeapullrequest.com)
[![Educational](https://img.shields.io/badge/Purpose-Educational-blueviolet?style=for-the-badge)](https://github.com)

> **A modern C++ implementation of the RC4 stream cipher for file encryption and decryption.**  
> *Built for educational purposes and authorized security training.*

[Features](#-features) • [Quick Start](#-quick-start) • [Usage](#-usage) • [Screenshots](#-screenshots) • [Documentation](#-documentation)

</div>

---

## 📖 Overview

This project provides two command-line tools that demonstrate the **RC4 stream cipher** by encrypting and decrypting files. It's designed to help students and security enthusiasts understand how symmetric stream ciphers work in practice.

| Tool | Description |
|------|-------------|
| **`rc4_encryptor`** | 🔒 Encrypts any file using RC4 with a specified key |
| **`rc4_decryptor`** | 🔓 Decrypts files encrypted with RC4 using the same key |

---

## ✨ Features

<div align="center">

| Feature | Description |
|---------|-------------|
| 🚀 **Full RC4 Implementation** | KSA + PRGA with proper byte-wise encryption |
| 📁 **Any File Support** | Works with text, binary, images, and more |
| 🎨 **Beautiful CLI Output** | Colored tables, hex dumps, and progress indicators |
| 🔍 **Readability Check** | Automatically detects if decryption key is wrong |
| 📊 **Hex Preview** | Shows encrypted data in hexadecimal format |
| ⚡ **Cross-Platform** | Works on Linux, macOS, and Windows |
| 📝 **Educational Focus** | Clean, well-documented code for learning |

</div>

---

## 🚀 Quick Start

### Prerequisites

- **C++17 compiler** (GCC 7+, Clang 5+, or MSVC 2017+)
- **No external dependencies** – uses only the standard library




## 📸 Screenshot
<div align="center">

# 🗡️ ORDOVAS SHADOW TILES

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

**ORDOVAS SHADOW TILES** provides two command-line tools that demonstrate the **RC4 stream cipher** by encrypting and decrypting files. This project is designed for students and security enthusiasts to understand how symmetric stream ciphers work in practice.

| Tool | Description |
|------|-------------|
| **`rc4_encryptor`** | 🔒 Encrypts any file using RC4 with a specified key |
| **`rc4_decryptor`** | 🔓 Decrypts files encrypted with RC4 using the same key |

---

## ✨ Features

| Feature | Description |
|---------|-------------|
| 🚀 **Full RC4 Implementation** | KSA + PRGA with proper byte-wise encryption |
| 📁 **Any File Support** | Works with text, binary, images, and more |
| 🎨 **Beautiful CLI Output** | Colored tables, hex dumps, and progress indicators |
| 🔍 **Readability Check** | Automatically detects if decryption key is wrong |
| 📊 **Hex Preview** | Shows encrypted data in hexadecimal format |
| ⚡ **Cross-Platform** | Works on Linux, macOS, and Windows |
| 📝 **Educational Focus** | Clean, well-documented code for learning |

---
### Installation
### Encryption Output

```bash
# Clone the repository
git clone https://github.com/yourusername/rc4-encryptor.git
cd rc4-encryptor

# Compile
make          # or: g++ -std=c++17 -o rc4_encryptor rc4_encryptor.cpp
make decrypt  # or: g++ -std=c++17 -o rc4_decryptor rc4_decryptor.cpp

# Run
./rc4_encryptor file.txt "mysecretkey"
./rc4_decryptor file.txt "mysecretkey" restored.txt

