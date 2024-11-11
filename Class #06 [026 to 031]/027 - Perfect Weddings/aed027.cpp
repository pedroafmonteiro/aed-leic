#include <iostream>
#include <stack>
#include <list>

using namespace std;

void weddings(const string &e)
{
    stack<pair<char, int>> checks;
    list<pair<string, string>> closed;
    for (int i = 0; i < (int)e.size(); i++)
    {
        char c = e[i];
        if (c == '(' || c == '[' || c == '{')
        {
            checks.push({c, i});
        }
        else if (c == ')')
        {
            if (checks.empty()) checks.push({c, i});
            else if (checks.top().first == '(') {
                closed.push_back({"()", to_string(checks.top().second) + ' ' + to_string(i)});
                checks.pop();
            }
        }
        else if (c == ']')
        {
            if (checks.empty()) checks.push({c, i});
            else if (checks.top().first == '[') {
                closed.push_back({"[]", to_string(checks.top().second) + ' ' + to_string(i)});
                checks.pop();
            }
        }
        else if (c == '}')
        {
            if (checks.empty()) checks.push({c, i});
            else if (checks.top().first == '{') {
                closed.push_back({"{}", to_string(checks.top().second) + ' ' + to_string(i)});
                checks.pop();
            }
        }
    }
    if (!checks.empty()) {
        cout << "badly matched pairs" << endl;
        return;
    }
    else if (closed.empty()) {
        cout << "no brides and grooms to marry" << endl;
        return;
    }
    else {
        for (auto i : closed) {
            cout << i.first << ' ' << i.second << endl;
        }
        return;
    }
}

int main(int argc, char const *argv[])
{
    string input;
    cin >> input;

    weddings(input);

    return 0;
}
