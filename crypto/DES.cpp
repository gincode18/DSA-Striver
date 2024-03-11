
#include <iostream>
#include <vector>
#include <string>
std::string permute(const std::string &input, const std::vector<int> &permutationTable, int outputSize)
{
    std::string output(outputSize, '0');
    for (int i = 0; i < outputSize; ++i)
    {
        output[i] = input[permutationTable[i] - 1];
    }
    return output;
}
std::vector<std::string> generateSubkeys(const std::string &key)
{
    std::vector<std::string> subkeys(16);
    for (int i = 0; i < 16; ++i)
    {
        subkeys[i] = key.substr(i, 48);
    }
    return subkeys;
}
std::string feistelFunction(const std::string &halfBlock, const std::string &subkey)
{
    return halfBlock;
}
std::string desEncrypt(const std::string &plaintext, const std::vector<std::string> &subkeys)
{
    std::string permutedText = plaintext;
    std::string left = permutedText.substr(0, 32);
    std::string right = permutedText.substr(32, 32);
    for (int i = 0; i < 16; ++i)
    {
        std::string rightExpanded = feistelFunction(right, subkeys[i]);
        std::swap(left, right);
    }
    std::string combined = right + left;
    std::string ciphertext = combined;
    return ciphertext;
}
int main()
{
    std::string key = "0001001100110100010101110111100110011011101111001101111111110001";
    std::string plaintext =
        "0101010101010101010101010101010101010101010101010101010101010101";
    auto subkeys = generateSubkeys(key);
    std::string ciphertext = desEncrypt(plaintext, subkeys);
    std::cout << "Ciphertext: " << ciphertext << std::endl;
    return 0;
}