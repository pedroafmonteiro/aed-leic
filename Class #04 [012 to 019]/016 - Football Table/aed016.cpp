#include <iostream>
#include <sstream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

vector<string> calculatePoints(const string details) {
    vector<string> info;
    string teamName;
    int wins, draws, losses, goalsScored, goalsAgainst;
    int points, goalsAverage;
    istringstream iss(details);
    iss >> teamName >> wins >> draws >> losses >> goalsScored >> goalsAgainst;
    info.push_back(teamName);
    points = (wins * 3) + (draws);
    info.push_back(to_string(points));
    goalsAverage = goalsScored - goalsAgainst;
    info.push_back(to_string(goalsAverage));
    return info;
}

bool sortingAlgorithm(const vector<string>& team1, const vector<string>& team2) {
    int points1 = stoi(team1[1]);
    int points2 = stoi(team2[1]);
    int goalsAverage1 = stoi(team1[2]);
    int goalsAverage2 = stoi(team2[2]);

    if (points1 > points2) return true;
    else if (points1 == points2) {
        if (goalsAverage1 > goalsAverage2) return true;
        else if (goalsAverage1 < goalsAverage2) return false;
        else return team1[0] < team2[0];
    }
    return false;
}

int main(int argc, char const *argv[])
{
    int n;
    cin >> n;
    cin.ignore(); // Ignore the newline character left in the input buffer
    vector<vector<string>> teams;
    for (int i = 0; i < n; i++)
    {
        string teamDetails;
        getline(cin, teamDetails);
        teams.push_back(calculatePoints(teamDetails));
    }
    sort(teams.begin(), teams.end(), sortingAlgorithm);
    for (int i = 0; i < n; i++) {
        cout << teams[i][0] << ' ' << teams[i][1] << ' ' << teams[i][2] << endl;
    }
    return 0;
}
