#include <iostream>
#include <list>
#include <sstream>

using namespace std;

void game(list<string> &names, const int n) {
    auto itr = names.begin();
    while(!names.empty()) {
        int count = 0;
        while (true) {
            if (itr == names.end()) itr = names.begin();
            count++;
            if(count == n) break;
            itr++;
        }
        cout << *itr << endl;
        itr = names.erase(itr);
    }
}

int main(int argc, char const *argv[])
{
    // Get main phrase and count the words
    string phrase;
    getline(cin, phrase);
    istringstream iss(phrase);
    string word;
    int k = 0;
    while (iss >> word) k++;

    // Create names list and put them on it
    int n;
    list<string> names;
    cin >> n;
    for (int i = 0; i < n; i++) {
        string name;
        cin >> name;
        names.push_back(name);
    }

    game(names, k);
    return 0;
}