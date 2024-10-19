#include <iostream>
#include <vector>
#include <bitset>
#include <algorithm>

using namespace std;

int countBits(int n)
{
    int count = 0;
    string binary = bitset<32>(n).to_string();
    for (char c : binary)
    {
        if (c == '1')
            count++;
    }
    return count;
}

bool sortingFunction(const int &n1, const int &n2)
{
    int count1 = countBits(n1);
    int count2 = countBits(n2);
    if (count1 != count2)
    {
        return count1 > count2;
    }
    return n1 < n2;
}

int main(int argc, char const *argv[])
{
    int n;
    cin >> n;
    vector<int> numbers;
    for (int i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        numbers.push_back(x);
    }
    sort(numbers.begin(), numbers.end(), sortingFunction);
    for (int i = 0; i < n; i++) {
        cout << numbers[i] << endl;
    }
    return 0;
}
