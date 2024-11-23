#include <iostream>
#include <map>

using namespace std;

int main(int argc, char const *argv[])
{
    int n;
    cin >> n;
    map<int, int> events;
    for (int i = 0; i < n; i++)
    {
        int ai;
        cin >> ai;
        if (events.find(ai) != events.end()) {
            if (i == n - 1)
                cout << events[ai] << endl;
            else
                cout << events[ai] << " ";
            events[ai] = i + 1;
        } else {
            if (i == n - 1)
                cout << "-1" << endl;
            else
                cout << "-1 ";
            events[ai] = i + 1;
        }
    }
    return 0;
}
