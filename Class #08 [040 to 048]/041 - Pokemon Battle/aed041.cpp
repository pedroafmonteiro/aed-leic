#include <iostream>
#include <set>

using namespace std;

void game(multiset<int> &deck1, multiset<int> &deck2) {
    while (!deck1.empty() && !deck2.empty()) {
        if (*prev(deck1.end()) > *prev(deck2.end())) {
            int newHealth = *prev(deck1.end()) - *prev(deck2.end());
            deck2.erase(prev(deck2.end()));
            deck1.erase(prev(deck1.end()));
            deck1.insert(newHealth);
        } else if (*prev(deck1.end()) < *prev(deck2.end())) {
            int newHealth = *prev(deck2.end()) - *prev(deck1.end());
            deck2.erase(prev(deck2.end()));
            deck1.erase(prev(deck1.end()));
            deck2.insert(newHealth);
        } else {
            deck2.erase(prev(deck2.end()));
            deck1.erase(prev(deck1.end()));
        }
    }
    if (deck1.empty() && deck2.empty()) {
        cout << "Tie" << endl;
        cout << 0 << endl;
        return;
    } else if (deck1.empty()) {
        cout << "Bob wins" << endl;
        cout << deck2.size() << endl;
        return;
    } else {
        cout << "Alice wins" << endl;
        cout << deck1.size() << endl;
        return;
    }
}

int main(int argc, char const *argv[])
{
    int a;
    cin >> a;
    multiset<int> deckAlice;
    for (int i = 0; i < a; i++) {
        int ai;
        cin >> ai;
        deckAlice.insert(ai);
    }

    int b;
    cin >> b;
    multiset<int> deckBob;
    for (int i = 0; i < b; i++) {
        int bi;
        cin >> bi;
        deckBob.insert(bi);
    }

    game(deckAlice, deckBob);
    return 0;
}
