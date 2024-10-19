#include <iostream>
#include <vector>

using namespace std;

int search(const vector<int> &v, const int key)
{
    int low = 0, high = (int)v.size() - 1;
    while (low <= high)
    {
        int middle = low + (high - low) / 2;
        if (key < v[middle])
            high = middle - 1;
        else if (key > v[middle])
            low = middle + 1;
        else
            return middle; // found key
    }
    return -1;
}

int main(int argc, char const *argv[])
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
    int q;
    cin >> q;
    for (int i = 0; i < q; i++)
    {
        int x;
        cin >> x;
        cout << search(sequence, x) << endl;
    }
    return 0;
}
