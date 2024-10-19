#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int countInInterval(const vector<int> &v, const int a, const int b) {
    auto lowerBoundA = lower_bound(v.begin(), v.end(), a);
    auto upperBoundB = upper_bound(v.begin(), v.end(), b);
    return distance(lowerBoundA, upperBoundB);
}

int main(int argc, char const *argv[])
{
    int n;
    cin >> n;
    vector<int> sequence(n);
    for (int i = 0; i < n; i++) {
        cin >> sequence[i];
    }
    int q;
    cin >> q;
    for (int i = 0; i < q; i++) {
        int a, b;
        cin >> a >> b;
        cout << countInInterval(sequence, a, b) << endl;
    }
    return 0;
}