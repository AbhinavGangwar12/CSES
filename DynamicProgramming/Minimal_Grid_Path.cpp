#include<iostream>
#include<string>
#include<vector>

using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    if(!(cin>>n))return 0;
    vector<string> grid(n);
    for(int i = 0; i<n ;i++){
        cin>>grid[i];
    }
    vector<pair<int,int>> active_cells;
    vector<vector<int>> visited(n, vector<int>(n,0));
    string result = "";
    active_cells.push_back({0,0});
    visited[0][0] = 1;
    result+=grid[0][0];

    for(int i = 0; i<2*n-2;i++){
        char min_char = 'Z' + 1;
        vector<pair<int,int>> next_cells;

        for(auto cell: active_cells){
            int r = cell.first;
            int c = cell.second;

            if(r+1 < n && !visited[r+1][c]){
                visited[r+1][c] = 1;
                next_cells.push_back({r+1,c});
            }
            if(c+1 < n && !visited[r][c+1]){
                visited[r][c+1] = 1;
                next_cells.push_back({r,c+1});
            }
        }

        for(auto cell: next_cells){
            if(grid[cell.first][cell.second] < min_char){
                min_char = grid[cell.first][cell.second];
            }
        }

        active_cells.clear();
        for(auto cell: next_cells){
            if(grid[cell.first][cell.second] == min_char){
                active_cells.push_back(cell);
            }
        }
        result += min_char;
    }
    cout<<result<<"\n";
    return 0;
}