#include <iostream>
#include <string>
#include <vector>

std::string permute(std::string k, std::vector<int> arr, int n) {
    std::string permutation = "";
    for (int i = 0; i < n; i++) {
        permutation += k[arr[i] - 1];
    }
    return permutation;
}

std::pair<std::string, std::string> generateKeys(std::string key) {
    std::string k1 = key.substr(0, 8);
    std::string k2 = key.substr(2, 8);
    return std::make_pair(k1, k2); // Use make_pair
}

std::string sdesEncrypt(std::string plaintext, std::string key) {
    auto keys = generateKeys(key); // Store the pair returned by generateKeys
    std::string k1 = keys.first;
    std::string k2 = keys.second;

    std::string initialPermutation = plaintext;
    std::string afterRoundFunction = initialPermutation;
    std::string ciphertext = afterRoundFunction;
    return ciphertext;
}

int main() {
    std::string key = "1010000010";
    std::string plaintext = "11010111";
    std::string ciphertext = sdesEncrypt(plaintext, key);
    std::cout << "Ciphertext: " << ciphertext << std::endl;
    return 0;
}
