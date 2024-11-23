#include <iostream>
#include <map>

using namespace std;

int main(int argc, char const *argv[])
{
    int n;
    cin >> n;
    map<string, pair<int, int>> movies;
    for (int i = 0; i < n; i++) {
        string name;
        cin >> name;
        int review;
        cin >> review;
        movies[name].first++;
        if (review >= 5) movies[name].second++;
    }
    
    cout << movies.size() << endl;
    
    int max = 0;
    int count = 0;
    for (auto movie : movies) {
        if (movie.second.first > max) {
            max = movie.second.first;
            count = 1;
        } else if (movie.second.first == max) {
            count++;
        }
    }
    cout << max << " " << count << endl;
    
    int positive = 0;
    for (auto movie : movies) {
        if (movie.second.second > movie.second.first - movie.second.second) {
            positive++;
        }
    }
    cout << positive << endl;
    return 0;
}
