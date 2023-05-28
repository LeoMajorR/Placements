def Caesar_Encrypt(plainText, key):
    cipherText = ""
    for i in range(len(plainText)):
        char = plainText[i]
        if (char == " "):
            cipherText += " "
        elif (char.isupper()):
            cipherText += chr((ord(char) + key - 65) % 26 + 65)
        else:
            cipherText += chr((ord(char) + key - 97) % 26 + 97)
    return cipherText


def Caesar_Decrypt(cipherText, key):
    plainText = ""
    for i in range(len(cipherText)):
        char = cipherText[i]
        if (char == " "):
            plainText += " "
        elif (char.isupper()):
            plainText += chr((ord(char) - key - 65) % 26 + 65)
        else:
            plainText += chr((ord(char) - key - 97) % 26 + 97)
    return plainText


input_text = input("Enter the text to be encrypted: ")
key = 3
print("Encrypted text: ", Caesar_Encrypt(input_text, key))
encrypted_text = Caesar_Encrypt(input_text, key)
decrypted_text = Caesar_Decrypt(encrypted_text, key)
print("Decrypted text: ", decrypted_text)