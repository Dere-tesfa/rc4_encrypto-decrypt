/**
 * RC4 FILE DECRYPTOR – EDUCATIONAL
 * ================================
 * Decrypts a file encrypted with RC4 using the same key.
 * 
 * Compile:
 *   g++ -std=c++17 -o rc4_decryptor rc4_decryptor.cpp
 * 
 * Usage:
 *   ./rc4_decryptor <input_file> <key> [output_file]
 * 
 * Example:
 *   ./rc4_decryptor file.txt "mysecretkey" restored.txt
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
// RC4 IMPLEMENTATION (IDENTICAL TO ENCRYPTOR)
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

    std::vector<unsigned char> decrypt(const std::vector<unsigned char>& data) {
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

void print_ascii_preview(const std::vector<unsigned char>& data, size_t max_bytes = 200) {
    std::cout << Color::CYAN << "┌──────────────────────────────────────────────────────┐" << Color::RESET << std::endl;
    std::cout << Color::CYAN << "│" << Color::WHITE << std::setw(50) << std::right << " Decrypted Content Preview " << Color::CYAN << "│" << Color::RESET << std::endl;
    std::cout << Color::CYAN << "├──────────────────────────────────────────────────────┤" << Color::RESET << std::endl;
    std::cout << Color::CYAN << "│ " << Color::WHITE;
    
    size_t limit = std::min(max_bytes, data.size());
    for (size_t i = 0; i < limit; i++) {
        if (data[i] >= 32 && data[i] <= 126) {
            std::cout << data[i];
        } else if (data[i] == '\n') {
            std::cout << '\n';
        } else {
            std::cout << '.';
        }
    }
    if (data.size() > max_bytes) {
        std::cout << "...";
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
// MAIN DECRYPTOR
// ============================================================

int main(int argc, char* argv[]) {
    print_banner();
    
    std::cout << Color::MAGENTA << Color::BOLD;
    std::cout << "   RC4 File Decryptor – Educational" << std::endl;
    std::cout << Color::RESET;
    
    if (argc < 3) {
        print_info("", "");
        print_info("Usage:", "warning");
        print_info("  ./rc4_decryptor <input_file> <key> [output_file]", "info");
        print_info("", "");
        print_info("Example:", "warning");
        print_info("  ./rc4_decryptor file.txt \"mysecretkey\" restored.txt", "info");
        return 1;
    }
    
    std::string input_file = argv[1];
    std::string key_str = argv[2];
    std::string output_file = (argc >= 4) ? argv[3] : (input_file + ".decrypted");
    std::vector<unsigned char> key(key_str.begin(), key_str.end());
    
    try {
        // Read encrypted file
        std::vector<unsigned char> ciphertext = read_file(input_file);
        
        // Display file information
        print_table({
            {"File Name", input_file},
            {"Encrypted Size", std::to_string(ciphertext.size()) + " bytes"},
            {"Key", "\"" + key_str + "\""},
            {"Timestamp", get_current_time()}
        }, " File Information");
        
        print_info("Generating RC4 keystream for decryption...", "info");
        
        // Decrypt
        RC4 rc4(key.data(), key.size());
        std::vector<unsigned char> plaintext = rc4.decrypt(ciphertext);
        
        // Write decrypted file
        write_file(output_file, plaintext);
        
        print_info("Decryption complete! Saved to: " + output_file, "success");
        
        // Display decryption stats
        print_table({
            {"File Name", output_file},
            {"Decrypted Size", std::to_string(plaintext.size()) + " bytes"},
            {"Status", " DECRYPTED"}
        }, " Decryption Results");
        
        // Show preview
        print_info("Decrypted Content Preview:", "info");
        print_ascii_preview(plaintext, 200);
        
        // Check if decrypted content is readable text
        bool is_readable = true;
        for (unsigned char c : plaintext) {
            if (!(c >= 32 && c <= 126) && c != '\n' && c != '\r' && c != '\t') {
                is_readable = false;
                break;
            }
        }
        
        std::cout << std::endl;
        if (is_readable && !plaintext.empty()) {
            print_info("SUCCESS! The file is readable text.", "success");
            print_info("The original file has been restored exactly.", "success");
        } else {
            print_info("⚠️  WARNING: The decrypted content contains non-printable characters.", "warning");
            print_info("   This means the key is WRONG.", "warning");
            print_info("   Try decrypting with the exact key used for encryption.", "warning");
        }
        
    } catch (const std::exception& e) {
        print_info(e.what(), "error");
        return 1;
    }
    
    return 0;
}
