#include <iostream>
#include <vector>
#include <cmath>

long long public_key, private_key, n;

long long power(long long base, long long exponent, long long mod) {
    long long result = 1;
    while (exponent > 0) {
        if (exponent % 2 == 1) {
            result = (result * base) % mod;
        }
        exponent = exponent >> 1;
        base = (base * base) % mod;
    }
    return result;
}

long long encrypt(long long message) {
    return power(message, public_key, n);
}

long long decrypt(long long encrypted_text) {
    return power(encrypted_text, private_key, n);
}

std::vector<long long> encoder(const std::string& message) {
    std::vector<long long> encoded;
    for (char letter : message) {
        encoded.push_back(encrypt(static_cast<long long>(letter)));
    }
    return encoded;
}

std::string decoder(const std::vector<long long>& encoded) {
    std::string s;
    for (long long num : encoded) {
        s += static_cast<char>(decrypt(num));
    }
    return s;
}

void setkeys() {
    long long p, q, phi;

    std::cout << "Enter prime number p: ";
    std::cin >> p;
    std::cout << "Enter prime number q: ";
    std::cin >> q;

    std::cout << "Calculating modulus n = p * q..." << std::endl;
    n = p * q;
    std::cout << "Modulus n is set to: " << n << std::endl;

    phi = (p - 1) * (q - 1);

    std::cout << "Enter public key exponent e: ";
    std::cin >> public_key;

    std::cout << "Enter private key exponent d: ";
    std::cin >> private_key;
}

int main() {
    setkeys();

    std::cin.ignore(); // Ignore newline left in the input buffer
    std::cout << "\nEnter message: ";
    std::string message;
    std::getline(std::cin, message);

    auto coded = encoder(message);

    std::cout << "\nInitial message:\n" << message << std::endl;

    std::cout << "\nThe encoded message (encrypted by public key)\n";
    for (long long p : coded) {
        std::cout << p << " ";
    }

    std::string decrypted_message = decoder(coded);
    std::cout << "\n\nThe decoded message (decrypted by private key)\n" << decrypted_message << std::endl;

    return 0;
}
