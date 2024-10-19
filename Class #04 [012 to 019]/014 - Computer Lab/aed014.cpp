#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int countStudents(const vector<pair<int, int>> &v) {
    int count = 0;
    int max = 0;
    for (size_t i = 0; i < v.size(); i++) {
        if (v[i].second == 0) count++;
        else count--;
        if (count > max) max = count;
    }
    return max;
}

int main(int argc, char const *argv[])
{
    int n;
    cin >> n;
    vector<pair<int, int>> studentTimes;
    for (int i = 0; i < n; i++) {
        pair<int, int> time1, time2;
        cin >> time1.first;
        time1.second = 0;
        cin >> time2.first;
        time2.second = 1;
        studentTimes.push_back(time1);
        studentTimes.push_back(time2);
    }
    sort(studentTimes.begin(), studentTimes.end());
    cout << countStudents(studentTimes) << endl;
    return 0;
}