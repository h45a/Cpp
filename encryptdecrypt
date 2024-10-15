#include <iostream>
#include <string>

using namespace std;

class KeywordCipher {
private:
    string keyword;


    void generateKey(const string &message, string &key) {
        int messageLength = message.length();
        int keywordLength = keyword.length();
        key = "";
        
 
        for (int i = 0; i < messageLength; i++) {
            key += keyword[i % keywordLength]; 
        }
    }

public:
    KeywordCipher(const string &key) : keyword(key) {}


    string encrypt(const string &message) {
        string key;
        generateKey(message, key);
        string encryptedMessage = "";

        for (size_t i = 0; i < message.length(); i++) {
            char messageChar = message[i];
            char keyChar = key[i];

            char encryptedChar = (messageChar + keyChar) % 128; 
            encryptedMessage += encryptedChar;
        }

        return encryptedMessage;
    }

  
    string decrypt(const string &encryptedMessage) {
        string key;
        generateKey(encryptedMessage, key); 
        string decryptedMessage = "";

        for (size_t i = 0; i < encryptedMessage.length(); i++) {
            char encryptedChar = encryptedMessage[i];
            char keyChar = key[i];
          
            char decryptedChar = (encryptedChar - keyChar + 128) % 128;
            decryptedMessage += decryptedChar;
        }

        return decryptedMessage;
    }
};

int main() {
    string keyword;
    string message;
    cout<<"Enter message: "<<endl;
    getline(cin,message);

    cout<<"Enter the key: "<<endl;
   getline(cin,keyword);
    
    KeywordCipher cipher(keyword);

    string encryptedMessage = cipher.encrypt(message);
    string decryptedMessage = cipher.decrypt(encryptedMessage);

    cout << "Original Message: " << message << endl;
    cout << "Encrypted Message: " << encryptedMessage << endl;
    cout << "Decrypted Message: " << decryptedMessage << endl;

    return 0;
}
