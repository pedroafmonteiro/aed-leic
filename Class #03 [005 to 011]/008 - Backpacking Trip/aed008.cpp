#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool isPossible(const vector<int> &v, int x, int k) {
    int n = (int)v.size();
    int currentSum = v[0];
    int currentPartition = 1;
    for (int i = 1; i < n; i++) {
        currentSum += v[i];
        if (currentSum > x) {
            currentPartition++;
            currentSum = v[i];
        }
    }
    if (currentPartition > k) return false;
    return true;
}

int search(const vector<int> &v, int s, int k) {
    int low = *max_element(v.begin(), v.end()), high = s;
    while (low <= high) {
        int middle = low + (high - low) / 2;
        if (isPossible(v, middle, k)) {
            high = middle - 1;
        } else {
            low = middle + 1;
        }
    }
    return low;
}

int main(int argc, char const *argv[])
{
    int n, s = 0;
    cin >> n;
    vector<int> sequence;
    for (int i = 0; i < n; i++) {
        int d;
        cin >> d;
        s += d;
        sequence.push_back(d);
    }
    int q;
    cin >> q;
    for (int i = 0; i < q; i++) {
        int k;
        cin >> k;
        cout << search(sequence, s, k) << endl;
    }
    return 0;
}
