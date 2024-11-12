#include <iostream>
#include <vector>
#include <string>

using namespace std;

void compress(const string &input, int windowSize, vector<int> &offsets, vector<int> &lengths, vector<char> &nextChars) {
    int i = 0;

    while (i < input.length()) {
        int matchOffset = 0, matchLength = 0;

        int start = max(0, i - windowSize);

        for (int j = start; j < i; ++j) {
            int k = 0;
            while (i + k < input.length() && input[j + k] == input[i + k]) {
                ++k;
            }
            if (k > matchLength) {
                matchOffset = i - j;
                matchLength = k;
            }
        }

        offsets.push_back(matchOffset);
        lengths.push_back(matchLength);
        nextChars.push_back((i + matchLength < input.length()) ? input[i + matchLength] : '\0');

        i += matchLength + 1;
    }
}

int main() {
    string input = "abracadabra";
    int windowSize = 5;
    vector<int> offsets;
    vector<int> lengths;
    vector<char> nextChars;

    compress(input, windowSize, offsets, lengths, nextChars);

    cout << "LZ77 Compressed Data:\n";
    for (int i = 0; i < offsets.size(); ++i) {
        cout << "(" << offsets[i] << ", " << lengths[i] << ", " << nextChars[i] << ")\n";
    }

    return 0;
}
