
#include <iostream>
#include <string>

class Crypto {
public:
   virtual std::string Encode(std::string plaintext) = 0;
   virtual std::string Decode(std::string ciphertext) = 0;
};
class Substitution :public Crypto {
private:
    std::string _key;
public:
    Substitution(std::string key) {
        _key = key;
    }
    std::string Encode(std::string plaintext) override {
        std::string ciphertext = "";
        std::string alphabet_lower = "abcdefghijklmnopqrstuvwxyz";
        std::string alphabet_upper = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";

        for (char c : plaintext) {
            if (alphabet_lower.find(c) != std::string::npos) {
                int position = alphabet_lower.find(c);
                ciphertext += _key[position];
            }
            else if (alphabet_upper.find(c) != std::string::npos) {
                int position = alphabet_upper.find(c);
                ciphertext += toupper(_key[position]);
            }
            else {
                ciphertext += c;
            }
        }
        return ciphertext;
    }
    
    std::string Decode(std::string ciphertext) override {
        return Encode(ciphertext);
    }
};
int main()
{
    Substitution obj1("vpxniuchdfljtabqkewyszrmog");
    std::string plaintext = "Today is October 5th";
    std::cout << "Encrypted text: " << obj1.Encode(plaintext) << std::endl;
    std::string ciphertext = obj1.Encode(plaintext);
    std::cout << "Decoded text: " << obj1.Decode(ciphertext) << std::endl;
}

