def generate_key(text, key):
    key = list(key)
    if len(text) == len(key):
        return key
    else:
        for i in range(len(text) - len(key)):
            key.append(key[i % len(key)])
    return "".join(key)


def encrypt_vigenere(plaintext, key):
    ciphertext = []
    for i in range(len(plaintext)):
        char = (ord(plaintext[i]) + ord(key[i])) % 26
        char += ord('A')
        ciphertext.append(chr(char))
    return "".join(ciphertext)


def decrypt_vigenere(ciphertext, key):
    plaintext = []
    for i in range(len(ciphertext)):
        char = (ord(ciphertext[i]) - ord(key[i]) + 26) % 26
        char += ord('A')
        plaintext.append(chr(char))
    return "".join(plaintext)


if __name__ == "__main__":
    plaintext = input("Masukkan plaintext: ").upper().replace(" ", "")
    key = input("Masukkan kunci: ").upper().replace(" ", "")
    
    generated_key = generate_key(plaintext, key)
    print(f"Kunci yang digunakan: {generated_key}")

    ciphertext = encrypt_vigenere(plaintext, generated_key)
    print(f"Ciphertext: {ciphertext}")

    decrypted_text = decrypt_vigenere(ciphertext, generated_key)
    print(f"Hasil dekripsi: {decrypted_text}")
