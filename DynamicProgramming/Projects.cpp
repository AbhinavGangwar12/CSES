#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Project {
    int start;
    int end;
    int reward;
};

bool compareEnd(const Project &a, const Project &b) {
    return a.end < b.end;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    if (!(cin >> n)) return 0;

    vector<Project> projects(n);
    for (int i = 0; i < n; i++) {
        cin >> projects[i].start >> projects[i].end >> projects[i].reward;
    }

    sort(projects.begin(), projects.end(), compareEnd);

    vector<int> endDays;
    for (int i = 0; i < n; i++) {
        endDays.push_back(projects[i].end);
    }
    vector<long long> dp(n + 1, 0);

    for (int i = 0; i < n; i++) {

        long long exclude = dp[i]; 

        auto it = lower_bound(endDays.begin(), endDays.begin() + i, projects[i].start);
        int valid_projects_count = distance(endDays.begin(), it); 
        
        long long include = projects[i].reward + dp[valid_projects_count];

        dp[i + 1] = max(exclude, include);
    }

    cout << dp[n] << "\n";

    return 0;
}