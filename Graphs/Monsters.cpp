#include <iostream>
#include <vector>
#include <queue>
#include <string>
#include <algorithm>
#include <climits>

using namespace std;

int main() {
    // Optimize standard I/O operations for performance
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m;
    if (!(cin >> n >> m)) return 0;

    vector<string> grid(n);
    queue<pair<int, int>> q;
    vector<vector<int>> dist(n, vector<int>(m, INT_MAX));
    pair<int, int> start;

    // Read grid and initialize Monster and Player starting positions
    for (int i = 0; i < n; i++) {
        cin >> grid[i];
        for (int j = 0; j < m; j++) {
            if (grid[i][j] == 'A') {
                start = {i, j};
            } else if (grid[i][j] == 'M') {
                q.push({i, j});
                dist[i][j] = 0; // Fix: Initialize monster start distance to 0
            }
        }
    }

    int dx[] = {-1, 1, 0, 0};
    int dy[] = {0, 0, -1, 1};

    // Phase 1: Multi-source BFS for Monsters
    while (!q.empty()) {
        auto [x, y] = q.front();
        q.pop();

        for (int i = 0; i < 4; i++) {
            int nx = x + dx[i];
            int ny = y + dy[i];

            // Fix: Check bounds, walls, AND if we found a strictly shorter path
            if (nx >= 0 && nx < n && ny >= 0 && ny < m && grid[nx][ny] != '#') {
                if (dist[nx][ny] > dist[x][y] + 1) {
                    dist[nx][ny] = dist[x][y] + 1;
                    q.push({nx, ny});
                }
            }
        }
    }

    // Phase 2: BFS for Player ('A')
    queue<pair<int, int>> pq;
    pq.push(start);
    
    // We can reuse a distance array for the player to act as our 'visited' tracker
    vector<vector<int>> p_dist(n, vector<int>(m, INT_MAX));
    p_dist[start.first][start.second] = 0;
    
    vector<vector<pair<int, int>>> path(n, vector<pair<int, int>>(m, {-1, -1}));
    pair<int, int> exit_pos = {-1, -1};

    while (!pq.empty()) {
        auto [x, y] = pq.front();
        pq.pop();

        // Check if we hit the boundary
        if (x == 0 || x == n - 1 || y == 0 || y == m - 1) {
            exit_pos = {x, y};
            break; 
        }

        for (int i = 0; i < 4; i++) {
            int nx = x + dx[i];
            int ny = y + dy[i];

            if (nx >= 0 && nx < n && ny >= 0 && ny < m && grid[nx][ny] != '#') {
                // Fix: Ensure unvisited by player AND strictly faster than the monster
                if (p_dist[nx][ny] == INT_MAX && p_dist[x][y] + 1 < dist[nx][ny]) {
                    p_dist[nx][ny] = p_dist[x][y] + 1;
                    path[nx][ny] = {x, y};
                    pq.push({nx, ny});
                }
            }
        }
    }

    // Phase 3: Path Reconstruction & Output
    if (exit_pos.first != -1) { // Fix: Prevents Segfault if no exit is found
        cout << "YES\n";
        string result = "";
        pair<int, int> current = exit_pos;
        
        while (current != start) {
            pair<int, int> prev = path[current.first][current.second];
            if (prev.first == current.first - 1) result += 'D';
            else if (prev.first == current.first + 1) result += 'U';
            else if (prev.second == current.second - 1) result += 'R';
            else if (prev.second == current.second + 1) result += 'L';
            current = prev;
        }
        
        reverse(result.begin(), result.end());
        cout << result.length() << "\n"; // Fix: Problem asks for path length first
        cout << result << "\n";
    } else {
        cout << "NO\n";
    }

    return 0;
}