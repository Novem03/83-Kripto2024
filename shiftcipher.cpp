/*
Nama : Novem Romadhofi Kika
NPM : 140810220083
Kelas : A
Program : Shift Cipher
*/

#include <iostream>
#include <string>
using namespace std;

string encryptShiftCipher(string text, int key) {
    string result = "";
    
    for (int i = 0; i < text.length(); i++) {
        if (isupper(text[i])) {
            result += char(int(text[i] + key - 65) % 26 + 65);
        }

        else if (islower(text[i])) {
            result += char(int(text[i] + key - 97) % 26 + 97);
        }

        else {
            result += text[i];
        }
    }
    return result;
}

string decryptShiftCipher(string text, int key) {
    string result = "";
   
    for (int i = 0; i < text.length(); i++) {
        if (isupper(text[i])) {
            result += char(int(text[i] - key - 65 + 26) % 26 + 65);
        }
        else if (islower(text[i])) {
            result += char(int(text[i] - key - 97 + 26) % 26 + 97);
        }
        else {
            result += text[i];
        }
    }
    return result;
}

int main() {
    string text;
    int key;

    cout << "Masukkan teks: ";
    getline(cin, text);

    cout << "Masukkan kunci (shift): ";
    cin >> key;

    string encrypted = encryptShiftCipher(text, key);
    cout << "Hasil enkripsi: " << encrypted << endl;

    string decrypted = decryptShiftCipher(encrypted, key);
    cout << "Hasil dekripsi: " << decrypted << endl;

    return 0;
}
