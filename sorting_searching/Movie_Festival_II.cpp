#include <iostream>
#include <vector>
#include <algorithm>
#include <set>

using namespace std;

struct Movie {
    long long start, end;
};
    bool compareMovies(const Movie &a, const Movie &b) {
        if (a.end == b.end) {
            return a.start < b.start;
        }
        return a.end < b.end;
    }

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    long long n, k;
    if (!(cin >> n >> k)) return 0;
    
    vector<Movie> movies(n);
    for (int i = 0; i < n; i++) {
        cin >> movies[i].start >> movies[i].end;
    }
    
    sort(movies.begin(), movies.end(), compareMovies);
    multiset<long long> members;
    long long cnt = 0;
    
    for (const auto &movie : movies) {
        auto it = members.upper_bound(movie.start);
        if (it != members.begin()) {
            --it;
            members.erase(it);
            members.insert(movie.end);
            cnt++;
        } 
        else if (members.size() < k) {
            members.insert(movie.end);
            cnt++;
        }
    }
    
    cout << cnt << "\n";
    return 0;
}