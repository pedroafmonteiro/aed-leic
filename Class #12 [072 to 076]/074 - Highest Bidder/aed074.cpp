#include <iostream>
#include <queue>
#include <vector>
#include <string>

using namespace std;

struct Offer {
    string name;
    int price;
    bool operator<(const Offer& other) const {
        return price < other.price;
    }
};

int main(int argc, char const *argv[])
{
    int N;
    cin >> N;
    priority_queue<Offer> offers;
    vector<string> results;

    for (int i = 0; i < N; ++i) {
        string event;
        cin >> event;
        if (event == "OFFER") {
            string name;
            int price;
            cin >> name >> price;
            offers.push({name, price});
        } else if (event == "SALE") {
            Offer highest = offers.top();
            offers.pop();
            results.push_back(to_string(highest.price) + " " + highest.name);
        }
    }

    for (const string& result : results) {
        cout << result << endl;
    }

    return 0;
}