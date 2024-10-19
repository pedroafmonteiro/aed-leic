#include <iostream>
#include <algorithm>
#include <vector>
#include <string>

using namespace std;

string sortPhrase(const string &phrase) {
    string cleanedPhrase;
    for (char c : phrase) {
        if (c != ' ') {
            cleanedPhrase += tolower(c);
        }
    }
    sort(cleanedPhrase.begin(), cleanedPhrase.end());
    return cleanedPhrase;
}

int main() {
    int n;
    cin >> n;
    cin.ignore();
    vector<string> phrases;
    for (int i = 0; i < n; i++) {
        string phrase;
        getline(cin, phrase);
        string result = sortPhrase(phrase);
        phrases.push_back(result);
    }
    sort(phrases.begin(), phrases.end());
    int uniqueAnagrams = 0;
    for (int i = 0; i < n; i++) {
        if (phrases[i] == phrases[i + 1]) {
            uniqueAnagrams++;
            while (i < n - 1 && phrases[i] == phrases[i + 1])
            {
                i++;
            }
            
        }
    }
    cout << uniqueAnagrams << endl;
    return 0;
}
