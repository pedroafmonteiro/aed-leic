#include <iostream>
#include <queue>
#include <vector>

using namespace std;

int main(int argc, char const *argv[])
{
    int n;
    cin >> n;

    priority_queue<int, vector<int>, greater<int>> minHeap;
    for (int i = 0; i < n; ++i) {
        int length;
        cin >> length;
        minHeap.push(length);
    }

    int totalCost = 0;
    while (minHeap.size() > 1) {
        int first = minHeap.top();
        minHeap.pop();
        int second = minHeap.top();
        minHeap.pop();
        int cost = first + second;
        totalCost += cost;
        minHeap.push(cost);
    }

    cout << totalCost << endl;
    return 0;
}
