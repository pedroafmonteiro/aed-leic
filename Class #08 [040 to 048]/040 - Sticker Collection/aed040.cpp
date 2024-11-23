#include <iostream>
#include <set>

using namespace std;

void stickers(const set<int> &collection, const set<int> &bag) {
    int newStickersCount = 0;
    set<int> newStickers;
    for (auto i : bag) {
        if (collection.find(i) != collection.end()) {
            continue;
        } else {
            newStickersCount++;
            newStickers.insert(i);
        }
    }
    cout << newStickersCount << endl;
    for (auto it = newStickers.begin(); it != newStickers.end(); ++it) {
        if (it != newStickers.begin()) {
            cout << " ";
        }
        cout << *it;
    }
    if (newStickersCount != 0) cout << endl;
}

int main(int argc, char const *argv[])
{
    int c;
    cin >> c;
    set<int> currentCollection;
    for (int i = 0; i < c; i++) {
        int ci;
        cin >> ci;
        currentCollection.insert(ci);
    }
    int b;
    cin >> b;
    set<int> newBag;
    for (int i = 0; i < b; i++) {
        int bi;
        cin >> bi;
        newBag.insert(bi);
    }

    stickers(currentCollection, newBag);

    return 0;
}
