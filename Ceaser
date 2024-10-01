#include <iostream>
#include <string>

using namespace std;

class czr{
    public:
string caesarCipherEncode(const string& text, int shift) {
    string result = "";

    for (char c : text) {
       
        char shifted = c + shift;
        result += shifted;
    }

    return result;
}


string caesarCipherDecode(const string& text, int shift) {
    string result = "";

    for (char c : text) {
    
        char shifted = c - shift;
        result += shifted;
    }

    return result;
}
};
int main() {
    czr a;
    string input;
    int shift;

    cout << "Enter text to encode: ";
    getline(cin, input);

    cout << "Enter shift value: ";
    cin >> shift;


    string encoded = a.caesarCipherEncode(input, shift);
    cout << "Encoded text: " << encoded << endl;

 
    string decoded = a.caesarCipherDecode(encoded, shift);
    cout << "Decoded text: " << decoded << endl;

    return 0;
}
