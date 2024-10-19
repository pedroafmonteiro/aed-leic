#include <iostream>
#include <vector>

using namespace std;

int maxSum(const vector<int> &v)
{
    int n = v.size();
    int maxSoFar = v[0];
    int currentMax = v[0];

    for (int i = 1; i < n; i++)
    {
        currentMax = max(v[i], currentMax + v[i]);
        maxSoFar = max(maxSoFar, currentMax);
    }

    return maxSoFar;
}

int main()
{
    int n;
    cin >> n;
    vector<int> sequence;
    for (int i = 0; i < n; i++)
    {
        int q;
        cin >> q;
        sequence.push_back(q);
    }
    cout << maxSum(sequence) << endl;
    return 0;
}
