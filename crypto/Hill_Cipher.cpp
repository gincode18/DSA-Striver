#include <iostream>
#include <vector>
#include <string>
#include <cmath> // For sqrt function

using namespace std;

vector<vector<int> > getKeyMatrix(string key, int n) {
    vector<vector<int> > keyMatrix(n, vector<int>(n, 0));
    int idx = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            keyMatrix[i][j] = (key[idx] % 65);
            idx++;
        }
    }
    return keyMatrix;
}

string encrypt(string text, vector<vector<int> > keyMatrix) {
    string cipher = "";
    int n = keyMatrix.size();
    for (int i = 0; i < text.length(); i += n) {
        for (int j = 0; j < n; j++) {
            int temp = 0;
            for (int k = 0; k < n; k++) {
                temp += ((keyMatrix[j][k] * (text[i + k] % 65)) % 26);
            }
            cipher += (temp % 26 + 65);
        }
    }
    return cipher;
}

int main() {
    string text = "HELLO"; // Example plaintext
    string key = "GYBNQKURP"; // Example key

    // Ensure the text length is a multiple of the square root of the key length
    int n = sqrt(key.length());
    if (text.length() % n != 0) {
        text += string(n - (text.length() % n), 'X');
    }

    vector<vector<int> > keyMatrix = getKeyMatrix(key, n);
    string cipherText = encrypt(text, keyMatrix);

    cout << "Encrypted Text: " << cipherText << endl;

    return 0;
}
