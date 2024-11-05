#include <iostream>
#include <string>

using namespace std;

string runLengthEncode(const string &input) {
    string encoded = "";
    int n = input.length();

    for (int i = 0; i < n; i++) {
        int count = 1;
        while (i < n - 1 && input[i] == input[i + 1]) {
            count++;
            i++;
        }
        encoded += input[i];
        if (count > 1) {
            encoded += to_string(count);
                encoded += "FF";
        }
    }

    return encoded;
}
string runLengthDecode(const string &encoded) {
    string decoded = "";
    int n = encoded.length();
    int i = 0;

    while (i < n) {
        char currentChar = encoded[i];
        i++;

        string countStr = "";
        while (i < n && isdigit(encoded[i])) {
            countStr += encoded[i];
            i++;
        }

        int count = (countStr.empty()) ? 1 : stoi(countStr);
        
        decoded += string(count, currentChar);


        if (i < n && encoded[i] == 'F' && i + 1 < n && encoded[i + 1] == 'F') {
            i += 2; 
        }
    }

    return decoded;
}
int main() {
    string input;
    cout << "Enter a string to encode: ";
    getline(cin, input);  

    string encodedString = runLengthEncode(input);
    cout << "Encoded string: " << encodedString << endl;


    string decodedString = runLengthDecode(encodedString);
    cout << "Decoded string: " << decodedString << endl;

    return 0;
}
