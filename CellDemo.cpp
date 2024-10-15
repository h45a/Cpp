#include <iostream>
#include <string>

using namespace std;

class Alg{
    public:
string encrypt(string text, int key) {
    int textLength = text.length();
    int rows = (textLength + key - 1) / key;
    char grid[rows][key];

    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < key; j++) {
            grid[i][j] = ' '; 
        }
    }

    int index = 0;
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < key; j++) {
            if (index < textLength) {
                grid[i][j] = text[index++];
            }
        }
    }

    string ciphertext = "";
    for (int j = 0; j < key; j++) { 
        for (int i = 0; i < rows; i++) {
                ciphertext += grid[i][j];
        }
    }
    
    return ciphertext;
}

string decrypt(string ciphertext, int key) {
    int textLength = ciphertext.length();
    int rows = (textLength + key - 1) / key;
    char grid[rows][key];

    int index = 0;
    for (int j = 0; j < key; j++) { 
        for (int i = 0; i < rows; i++) {
            if (index < textLength) {
                grid[i][j] = ciphertext[index++];
            } else {
                grid[i][j] = ' '; 
            }
        }
    }

    string text = "";
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < key; j++) {
                text += grid[i][j];
        }
    }

    return text;
}
};
int main() {
    string text;
    int key;
Alg a;

    cout << "Enter text: ";
    getline(cin, text);
    cout << "Enter number of columns (key): ";
    cin >> key;

    string ciphertext = a.encrypt(text, key);
    cout << "Encrypted Text: " << ciphertext << endl;

    string decryptedText = a.decrypt(ciphertext, key);
    cout << "Decrypted Text: " << decryptedText << endl;

    return 0;
}
