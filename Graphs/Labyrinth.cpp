#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n, m;
    if(!(cin >> n >> m))return 0;
    vector<vector<char>> labyrinth(n, vector<char>(m));
    pair<int,int> start, end;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            cin>>labyrinth[i][j];
            if(labyrinth[i][j] == 'A') start = {i, j};
            if(labyrinth[i][j] == 'B') end = {i, j};
        }
    }

    vector<vector<bool>> visited(n, vector<bool> (m, false));
    vector<vector<int>> path(n, vector<int> (m, -1));
    queue<pair<int,int>> q;
    string directions = "DULR";
    int X[] = {1, -1, 0, 0};
    int y[] = {0, 0, -1, 1};

    q.push(start);
    visited[start.first][start.second] = true;

    while(!q.empty()){
        pair<int,int> curr = q.front();q.pop();
        for(int i = 0; i < 4; i++){
            pair<int,int> next = {curr.first + X[i], curr.second + y[i]};
            if(next.first < 0 || next.second < 0 || next.first >= n || next.second >= m) continue;
            if(labyrinth[next.first][next.second] == '#' || visited[next.first][next.second]) continue;
            visited[next.first][next.second] = true;
            path[next.first][next.second] = i;
            q.push(next);
        }
    }
    if(visited[end.first][end.second]){
        cout<<"YES\n";
        vector<int> steps;
        while(end != start){
            int dir = path[end.first][end.second];
            steps.push_back(dir);
            end.first -= X[dir];
            end.second -= y[dir];
        }
        reverse(steps.begin(), steps.end());
        cout<<steps.size();
        cout<<"\n";
        for(int dir : steps){
            cout<<directions[dir];
        }
        cout<<"\n";
    }
    else{
        cout<<"NO\n";
    }
    return 0;
}