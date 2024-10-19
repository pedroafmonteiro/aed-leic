#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(int argc, char const *argv[])
{
    int n, k;
    cin >> n;
    cin >> k;
    vector<int> skill;
    for (int i = 0; i < n; i++) {
        int s;
        cin >> s;
        skill.push_back(s);
    }
    sort(skill.begin(), skill.end());
    for (int i = 0; i < k; i++) {
        cout << skill[n - i - 1] << endl;
    }
    return 0;
}
