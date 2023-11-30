#include <iostream>
#include <string>

std::string extendKey(const std::string& text, const std::string& key) {
    std::string longKey;
    size_t keyIndex = 0;

    for (char c : text) {
        if (isalpha(c)) { 
            longKey += toupper(key[keyIndex]); 
            keyIndex = (keyIndex + 1) % key.length();
        } else {
            longKey += c; 
        }
    }

    return longKey;
}

std::string vigenereEncode(const std::string& text, const std::string& key) {
    std::string result;
    std::string longKey = extendKey(text, key);

    for (size_t i = 0; i < text.length(); ++i) {
        if (isalpha(text[i])) {
            result += (toupper(text[i]) - 'A' + toupper(longKey[i]) - 'A') % 26 + 'A';
        } else {
            result += text[i];
        }
    }

    return result;
}

std::string vigenereDecode(const std::string& encodedText, const std::string& key) {
    std::string result;
    std::string longKey = extendKey(encodedText, key);

    for (size_t i = 0; i < encodedText.length(); ++i) {
        if (isalpha(encodedText[i])) {
            result += (toupper(encodedText[i]) - toupper(longKey[i]) + 26) % 26 + 'A';
        } else {
            result += encodedText[i];
        }
    }

    return result;
}

int main() {
    std::string text, key;

    std::cout << "Enter the text: ";
    std::getline(std::cin, text);
    std::cout << "Enter the key: ";
    std::getline(std::cin, key);

    std::string encodedText = vigenereEncode(text, key);
    std::cout << "Encoded Text: " << encodedText << std::endl;

    std::string decodedText = vigenereDecode(encodedText, key);
    std::cout << "Decoded Text: " << decodedText << std::endl;

    return 0;
}
