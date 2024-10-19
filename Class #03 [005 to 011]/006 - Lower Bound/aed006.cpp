#include <iostream>
#include <vector>

using namespace std;

int lowerBound(const vector<int> &v, const int key)
{
    auto low = v.begin(), high = v.end();
    while (low < high)
    {
        auto middle = low + (high - low) / 2;
        if (key <= *middle)
            high = middle;
        else
            low = middle + 1;
    }
    if (low != v.end() && *low >= key)
        return distance(v.begin(), low);
    return -1;
}

int main(int argc, char const *argv[])
{
    int n;
    cin >> n;
    vector<int> sequence(n);
    for (int i = 0; i < n; i++)
    {
        cin >> sequence[i];
    }
    int q;
    cin >> q;
    for (int i = 0; i < q; i++)
    {
        int x;
        cin >> x;
        cout << lowerBound(sequence, x) << endl;
    }
    return 0;
}
