#include <iostream>
#include <set>
#include <climits>

using namespace std;

#include <vector>
#include <algorithm>

vector<int> closestSums(const set<int>& s, const int x) {
    vector<int> sums;
    int minDiff = INT_MAX;
    set<int> uniqueSums;
    vector<int> sortedS(s.begin(), s.end());

    int left = 0, right = sortedS.size() - 1;
    while (left < right) {
        int sum = sortedS[left] + sortedS[right];
        int diff = abs(x - sum);
        if (diff < minDiff) {
            minDiff = diff;
            uniqueSums.clear();
            uniqueSums.insert(sum);
        } else if (diff == minDiff) {
            uniqueSums.insert(sum);
        }

        if (sum < x) {
            ++left;
        } else {
            --right;
        }
    }

    sums.assign(uniqueSums.begin(), uniqueSums.end());
    return sums;
}

int main(int argc, char const *argv[])
{
    int n, q;
    cin >> n;
    set<int> numbersSet;
    for (int i = 0; i < n; i++) {
        int s;
        cin >> s;
        numbersSet.insert(s);
    }
    cin >> q;
    for (int i = 0; i < q; i++) {
        int x;
        cin >> x;
        vector<int> sums = closestSums(numbersSet, x);
        for (size_t j = 0; j < sums.size(); ++j) {
            cout << sums[j];
            if (j == sums.size() - 1) {
            cout << endl;
            } else {
            cout << " ";
            }
        }
    }
    return 0;
}
