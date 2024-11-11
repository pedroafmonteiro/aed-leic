#include <iostream>
#include <queue>

using namespace std;

void handleProcesses(queue<pair<string, int>> &processes, const int t) {
    int iteration_count = 0;
    int total_time = 0;
    while (!processes.empty()) {
        if (processes.front().second > t) {
            iteration_count++;
            total_time+= t;
            int new_time = processes.front().second - t;
            processes.push({processes.front().first, new_time});
            processes.pop();
        }
        else
        {
            iteration_count++;
            total_time+= processes.front().second;
            cout << processes.front().first << ' ' << total_time << ' ' << iteration_count << endl;
            processes.pop();
        }
    }
}

int main(int argc, char const *argv[])
{
    int t, n;
    queue<pair<string, int>> taskmgr;
    cin >> t;
    cin >> n;
    for (int i = 0; i < n; i++) {
        string process_name;
        int process_time;
        cin >> process_name;
        cin >> process_time;
        taskmgr.push({process_name, process_time});
    }

    handleProcesses(taskmgr, t);

    return 0;
}
