#include <iostream>
#include <vector>
#include <string>

using namespace std;

void dfs(int i, int j, int n, int m, const vector<string> &rooms, vector<vector<bool>> &visited) {
    if (i < 0 || j < 0 || i >= n || j >= m)
        return;
        
    if (rooms[i][j] == '#' || visited[i][j])
        return;

    visited[i][j] = true;

    dfs(i - 1, j, n, m, rooms, visited);
    dfs(i + 1, j, n, m, rooms, visited);
    dfs(i, j - 1, n, m, rooms, visited);
    dfs(i, j + 1, n, m, rooms, visited);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m;
    if (!(cin >> n >> m)) return 0;

    vector<string> rooms(n);
    for (int i = 0; i < n; i++) {
        cin >> rooms[i];
    }

    vector<vector<bool>> visited(n, vector<bool>(m, false));
    int num_rooms = 0;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (rooms[i][j] == '.' && !visited[i][j]) {
                dfs(i, j, n, m, rooms, visited);
                num_rooms++;
            }
        }
    }

    cout << num_rooms << "\n";
    return 0;
}