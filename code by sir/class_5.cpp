#include <iostream>
#include <map>
using namespace std;

void countFrequency(const string &s, map<char, int> &freq) {
    for (char c : s) {
        freq[c]++;
    }
}

int main() {
    string s;
    cin>>s;
    map<char, int> freq;

    countFrequency(s, freq);

    cout << "Character Frequencies:\n";
    for (auto &p : freq) {
        cout << p.first << ": " << p.second << endl;
    }

    return 0;
}
