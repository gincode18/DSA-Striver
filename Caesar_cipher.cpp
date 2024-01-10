#include <iostream>
#include <string>

using namespace std;

// Function to encrypt the plaintext
string caesarEncrypt(string text, int shift) {
    string result = "";

    for (int i = 0; i < text.length(); i++) {
        char c = text[i];

        if (isalpha(c)) {
            char base = islower(c) ? 'a' : 'A';
            c = static_cast<char>((c + shift - base) % 26 + base);
        }
        
        result += c;
    }

    return result;
}

// Function to decrypt the ciphertext
string caesarDecrypt(string text, int shift) {
    return caesarEncrypt(text, 26 - shift);
}

int main() {
    string text;
    int shift;

    cout << "Enter the text: ";
    getline(cin, text);
    cout << "Enter shift value: ";
    cin >> shift;

    string encrypted = caesarEncrypt(text, shift);
    cout << "Encrypted Text: " << encrypted << endl;

    string decrypted = caesarDecrypt(encrypted, shift);
    cout << "Decrypted Text: " << decrypted << endl;

    return 0;
}
