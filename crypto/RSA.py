import random
import math

# Global variables for public and private keys, and modulus n
public_key = None
private_key = None
n = None

def encrypt(message):
    global public_key, n
    e = public_key
    encrypted_text = 1
    while e > 0:
        encrypted_text *= message
        encrypted_text %= n
        e -= 1
    return encrypted_text

def decrypt(encrypted_text):
    global private_key, n
    d = private_key
    decrypted = 1
    while d > 0:
        decrypted *= encrypted_text
        decrypted %= n
        d -= 1
    return decrypted

def encoder(message):
    encoded = []
    for letter in message:
        encoded.append(encrypt(ord(letter)))
    return encoded

def decoder(encoded):
    s = ''
    for num in encoded:
        s += chr(decrypt(num))
    return s

def setkeys():
    global public_key, private_key, n
    # Remove automatic prime generation and take inputs from the user
    p = int(input("Enter prime number p: "))
    q = int(input("Enter prime number q: "))
    
    n = p * q
    phi = (p - 1) * (q - 1)
    
    e = int(input("Enter public key exponent e: "))
    public_key = e
    
    d = int(input("Enter private key exponent d: "))
    private_key = d

# Set keys based on user input
setkeys()

# Input message from user
message = input("\n\nEnter message: ")
coded = encoder(message)

print("\n\nInitial message:")
print(message)

print("\n\nThe encoded message (encrypted by public key)\n")
print(''.join(str(p) for p in coded))

print("\n\nThe decoded message (decrypted by private key)\n")
print(decoder(coded))
print('\n\n')
