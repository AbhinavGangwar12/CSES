#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Task {
    long long duration;
    long long deadline;
};

bool compareTasks(const Task& t1, const Task& t2) {
    return t1.duration < t2.duration;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    if (!(cin >> n)) return 0;

    vector<Task> tasks(n);
    for (int i = 0; i < n; ++i) {
        cin >> tasks[i].duration >> tasks[i].deadline;
    }
    sort(tasks.begin(), tasks.end(), compareTasks);

    long long current_time = 0;
    long long total_reward = 0;

    for (int i = 0; i < n; ++i) {
        current_time += tasks[i].duration;
        total_reward += (tasks[i].deadline - current_time);
    }

    cout << total_reward << "\n";

    return 0;
}