#include <iostream>
#include <set>

using namespace std;

int closestSum(const set<int> s, const int x) {
    int closest = *s.begin() + *next(s.begin());
    int minDiff = abs(x - closest);

    for (auto it1 = s.begin(); it1 != s.end(); ++it1) {
        for (auto it2 = next(it1); it2 != s.end(); ++it2) {
            int sum = *it1 + *it2;
            int diff = abs(x - sum);
            if (diff < minDiff) {
                minDiff = diff;
                closest = sum;
            }
        }
    }

    return closest;
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
        cout << closestSum(numbersSet, x) << endl;
    }
    return 0;
}
