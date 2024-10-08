#include <iostream>
#include <string>
using namespace std;

class Alg {
public:
    string encryptDecrypt(string input, int key) {
        int len = input.size();
        int row = (len + key - 1) / key;
        char mat[row][key];


        for (int i = 0; i < row; i++) {
            for (int j = 0; j < key; j++) {
                int index = (i * key) + j;
                if (index < len) {
                    mat[i][j] = input[index];
                } else {
                    mat[i][j] = ' '; 
                }
            }
        }

        string output = "";
        
        for (int j = 0; j < key; j++) {
            for (int i = 0; i < row; i++) {
                output += mat[i][j];
            }
        }

        return output;
    }
};

int main() {
    int key;
    string text;
    cout << "Enter the text: " << endl;
    getline(cin, text);

    cout << "Enter the key: (number: 2, 3... )" << endl;
    cin >> key;

    Alg a;
    string encryptedText = a.encryptDecrypt(text, key);

    cout << "Original: " << text << endl;
    cout << "Encrypted: " << encryptedText << endl;

    string decryptedText = a.encryptDecrypt(encryptedText, key); 
    cout << "Decrypted: " << decryptedText << endl;

    return 0;
}
