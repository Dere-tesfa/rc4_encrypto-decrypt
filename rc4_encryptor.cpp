/**
 * RC4 FILE ENCRYPTOR – EDUCATIONAL
 * ================================
 * Encrypts a file using the RC4 stream cipher.
 * 
 * Compile:
 *   g++ -std=c++17 -o rc4_encryptor rc4_encryptor.cpp
 * 
 * Usage:
 *   ./rc4_encryptor <input_file> <key>
 * 
 * Example:
 *   ./rc4_encryptor file.txt "mysecretkey"
 */

#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <iomanip>
#include <chrono>
#include <ctime>

// ============================================================
// COLOR CODES FOR OUTPUT
// ============================================================

namespace Color {
    const std::string RESET   = "\033[0m";
    const std::string RED     = "\033[91m";
    const std::string GREEN   = "\033[92m";
    const std::string YELLOW  = "\033[93m";
    const std::string BLUE    = "\033[94m";
    const std::string MAGENTA = "\033[95m";
    const std::string CYAN    = "\033[96m";
    const std::string WHITE   = "\033[97m";
    const std::string BOLD    = "\033[1m";
}

// ============================================================
// RC4 IMPLEMENTATION (Same for Encryptor & Decryptor)
// ============================================================

class RC4 {
private:
    unsigned char S[256];
    int i, j;

    void init(const unsigned char* key, size_t key_len) {
        for (int k = 0; k < 256; k++) {
            S[k] = k;
        }
        
        int j = 0;
        for (int k = 0; k < 256; k++) {
            j = (j + S[k] + key[k % key_len]) & 0xFF;
            std::swap(S[k], S[j]);
        }
        i = 0;
        j = 0;
    }

    unsigned char generate_keystream_byte() {
        i = (i + 1) & 0xFF;
        j = (j + S[i]) & 0xFF;
        std::swap(S[i], S[j]);
        return S[(S[i] + S[j]) & 0xFF];
    }

public:
    RC4(const unsigned char* key, size_t key_len) {
        init(key, key_len);
    }

    std::vector<unsigned char> encrypt(const std::vector<unsigned char>& data) {
        std::vector<unsigned char> result(data.size());
        for (size_t k = 0; k < data.size(); k++) {
            result[k] = data[k] ^ generate_keystream_byte();
        }
        return result;
    }
};

// ============================================================
// UTILITY FUNCTIONS
// ============================================================

std::string get_current_time() {
    auto now = std::chrono::system_clock::now();
    auto in_time_t = std::chrono::system_clock::to_time_t(now);
    std::string time_str = std::ctime(&in_time_t);
    time_str.pop_back();
    return time_str;
}

void print_info(const std::string& message, const std::string& type = "info") {
    if (type == "info") {
        std::cout << Color::BLUE << "[*] " << message << Color::RESET << std::endl;
    } else if (type == "success") {
        std::cout << Color::GREEN << "[+] " << message << Color::RESET << std::endl;
    } else if (type == "warning") {
        std::cout << Color::YELLOW << "[!] " << message << Color::RESET << std::endl;
    } else if (type == "error") {
        std::cout << Color::RED << "[-] " << message << Color::RESET << std::endl;
    }
}

void print_banner() {
    std::cout << Color::CYAN << Color::BOLD;
    std::cout << "╔═══════════════════════════════════════════════════════════════════╗" << std::endl;
    std::cout << "║  ╔═╗╔═╗╔╦╗╔═╗╦ ╦╔═╗╔═╗  ╔═╗╦ ╦╔═╗╔═╗╔═╗╦╔═╗╔╦╗╦╔═╗╔═╗  ╔═╗╔╦╗╔═╗╔═╗  ║" << std::endl;
    std::cout << "║  ║ ║╠═╣ ║ ║ ║║║║╠═╣╚═╗  ╚═╗╠═╣╠═╣║ ║║ ║║╠═╣ ║ ║║ ║╚═╗  ╠═╣ ║ ║╣ ╚═╗  ║" << std::endl;
    std::cout << "║  ╚═╝╩ ╩ ╩ ╚═╝╚╩╝╩ ╩╚═╝  ╚═╝╩ ╩╩ ╩╚═╝╚═╝╩╩ ╩ ╩ ╩╚═╝╚═╝  ╩ ╩ ╩ ╚═╝╚═╝  ║" << std::endl;
    std::cout << "║                                                                   ║" << std::endl;
    std::cout << "║               ██████╗ ██████╗  ██████╗ ███████╗                    ║" << std::endl;
    std::cout << "║              ██╔════╝██╔═══╝ ██╔═══╝ ██╔════╝                    ║" << std::endl;
    std::cout << "║              ██████╗ █████╗  █████╗  █████╗                       ║" << std::endl;
    std::cout << "║              ██╔═══╝ ██╔══╝  ██╔══╝  ██╔══╝                       ║" << std::endl;
    std::cout << "║              ██║     ███████╗███████╗███████╗                     ║" << std::endl;
    std::cout << "║              ╚═╝     ╚══════╝╚══════╝╚══════╝                     ║" << std::endl;
    std::cout << "╚═══════════════════════════════════════════════════════════════════╝" << std::endl;
    std::cout << Color::RESET;
}

void print_table(const std::vector<std::pair<std::string, std::string>>& data, const std::string& title) {
    std::cout << Color::CYAN << "┌──────────────────────────────────────────────────────┐" << Color::RESET << std::endl;
    std::cout << Color::CYAN << "│" << Color::WHITE << std::setw(50) << std::right << " " + title + " " << Color::CYAN << "│" << Color::RESET << std::endl;
    std::cout << Color::CYAN << "├──────────────────────┬───────────────────────────────┤" << Color::RESET << std::endl;
    
    for (const auto& [key, value] : data) {
        std::cout << Color::CYAN << "│ " << Color::WHITE << std::setw(20) << std::left << key.substr(0, 20);
        std::cout << Color::CYAN << " │ " << Color::WHITE << std::setw(29) << std::left << value.substr(0, 29);
        std::cout << Color::CYAN << "│" << Color::RESET << std::endl;
    }
    
    std::cout << Color::CYAN << "└──────────────────────┴───────────────────────────────┘" << Color::RESET << std::endl;
}

void print_hex_dump(const std::vector<unsigned char>& data, size_t max_bytes = 32) {
    std::cout << Color::CYAN << "┌──────────────────────────────────────────────────────┐" << Color::RESET << std::endl;
    std::cout << Color::CYAN << "│" << Color::WHITE << std::setw(50) << std::right << " Hex Dump (first " << max_bytes << " bytes) " << Color::CYAN << "│" << Color::RESET << std::endl;
    std::cout << Color::CYAN << "├──────────────────────────────────────────────────────┤" << Color::RESET << std::endl;
    
    size_t limit = std::min(max_bytes, data.size());
    std::cout << Color::CYAN << "│ " << Color::WHITE;
    for (size_t i = 0; i < limit; i++) {
        std::cout << std::hex << std::setw(2) << std::setfill('0') << (int)data[i] << " ";
        if ((i + 1) % 8 == 0) std::cout << " ";
    }
    std::cout << Color::CYAN << " │" << Color::RESET << std::endl;
    std::cout << Color::CYAN << "└──────────────────────────────────────────────────────┘" << Color::RESET << std::endl;
}

// ============================================================
// FILE OPERATIONS
// ============================================================

std::vector<unsigned char> read_file(const std::string& filename) {
    std::ifstream file(filename, std::ios::binary | std::ios::ate);
    if (!file) {
        throw std::runtime_error("Could not open file: " + filename);
    }
    
    std::streamsize size = file.tellg();
    file.seekg(0, std::ios::beg);
    
    std::vector<unsigned char> data(size);
    if (!file.read(reinterpret_cast<char*>(data.data()), size)) {
        throw std::runtime_error("Error reading file: " + filename);
    }
    
    return data;
}

void write_file(const std::string& filename, const std::vector<unsigned char>& data) {
    std::ofstream file(filename, std::ios::binary);
    if (!file) {
        throw std::runtime_error("Could not write file: " + filename);
    }
    
    file.write(reinterpret_cast<const char*>(data.data()), data.size());
}

// ============================================================
// MAIN ENCRYPTOR
// ============================================================

int main(int argc, char* argv[]) {
    print_banner();
    
    std::cout << Color::MAGENTA << Color::BOLD;
    std::cout << "  🔐 RC4 File Encryptor – Educational" << std::endl;
    std::cout << Color::RESET;
    
    if (argc < 3) {
        print_info("", "");
        print_info("Usage:", "warning");
        print_info("  ./rc4_encryptor <input_file> <key>", "info");
        print_info("", "");
        print_info("Example:", "warning");
        print_info("  ./rc4_encryptor file.txt \"mysecretkey\"", "info");
        return 1;
    }
    
    std::string input_file = argv[1];
    std::string key_str = argv[2];
    std::vector<unsigned char> key(key_str.begin(), key_str.end());
    
    try {
        // Read file
        std::vector<unsigned char> plaintext = read_file(input_file);
        
        // Display file information
        print_table({
            {"File Name", input_file},
            {"Original Size", std::to_string(plaintext.size()) + " bytes"},
            {"Key", "\"" + key_str + "\""},
            {"Timestamp", get_current_time()}
        }, " File Information");
        
        print_info("Generating RC4 keystream...", "info");
        
        // Encrypt
        RC4 rc4(key.data(), key.size());
        std::vector<unsigned char> ciphertext = rc4.encrypt(plaintext);
        
        // Write encrypted file
        write_file(input_file, ciphertext);
        
        print_info("Encryption complete!", "success");
        
        // Display encryption stats
        print_table({
            {"File Name", input_file},
            {"Encrypted Size", std::to_string(ciphertext.size()) + " bytes"},
            {"Status", " ENCRYPTED"}
        }, " Encryption Results");
        
        // Show hex preview
        print_info("Encrypted Data Preview (first 32 bytes):", "info");
        print_hex_dump(ciphertext, 32);
        
        print_info("", "");
        print_info("To decrypt, run:", "warning");
        print_info("  ./rc4_decryptor " + input_file + " \"" + key_str + "\"", "info");
        
    } catch (const std::exception& e) {
        print_info(e.what(), "error");
        return 1;
    }
    
    return 0;
}
