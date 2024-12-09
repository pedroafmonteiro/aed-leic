#include <iostream>
#include <map>

using namespace std;

int coolSequences(map<int, int> &sequences) {
    int count = 0;
    for (auto p : sequences) {
        if (p.first > p.second) {
            for (int i = 0; i < p.second; i++) count++;
        } else if (p.first < p.second) {
            while (p.first != p.second) {
                count++;
                p.second--;
            }
        } else {
            continue;
        }
    }
    return count;
}

int main(int argc, char const *argv[])
{
    map<int, int> sequences;
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        int s;
        cin >> s;
        sequences[s]++;
    }
    cout << coolSequences(sequences) << endl;
    return 0;
}
