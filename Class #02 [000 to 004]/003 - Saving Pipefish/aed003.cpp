#include <iostream>
#include <vector>

using namespace std;

int savingPipefish(const vector<int>& v, const int k, const int t) {
    int count = 0;
    int subcount = 0;

    for (int j = 0; j < k; j++) {
        if (v[j] >= t) subcount++;
    }
    if (subcount >= (k / 2.0)) count++;

    for (int i = 1; i <= (int)v.size() - k; i++) {
        if (v[i - 1] >= t) subcount--;
        if (v[i + k - 1] >= t) subcount++;
        if (subcount >= (k / 2.0)) count++;
    }

    return count;
}

int main(int argc, char const *argv[])
{
    int n, k, t;
    cin >> n;
    cin >> k;
    cin >> t;
    vector<int> sequence;
    for (int i = 0; i < n; i++) {
        int s;
        cin >> s;
        sequence.push_back(s);
    }
    cout << savingPipefish(sequence, k, t) << endl;
    return 0;
}
