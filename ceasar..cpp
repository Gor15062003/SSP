#include <iostream>
#include <string>

std::string caesar_encrypt(const std::string& text, int shift) {
    std::string result = "";
    for (char ch : text) {
        if (isalpha(ch)) {
            // Determine whether the character is uppercase or lowercase
            bool is_upper = isupper(ch);
            
            // Shift the character by the specified amount
            char encrypted_ch = (ch - (is_upper ? 'A' : 'a') + shift + 26) % 26 + (is_upper ? 'A' : 'a');
            
            // Append the encrypted character to the result
            result += encrypted_ch;
        } else {
            // If the character is not a letter, leave it unchanged
            result += ch;
        }
    }
    return result;
}

std::string caesar_decrypt(const std::string& ciphertext, int shift) {
    // Decryption is essentially encryption with a negative shift
    return caesar_encrypt(ciphertext, -shift);
}

int main() {
    std::string plaintext = "Hello, World!";
    int shift_amount = 3;

    // Encrypt the plaintext
    std::string ciphertext = caesar_encrypt(plaintext, shift_amount);
    std::cout << "Encrypted: " << ciphertext << std::endl;

    // Decrypt the ciphertext
    std::string decrypted_text = caesar_decrypt(ciphertext, shift_amount);
    std::cout << "Decrypted: " << decrypted_text << std::endl;

    return 0;
}
