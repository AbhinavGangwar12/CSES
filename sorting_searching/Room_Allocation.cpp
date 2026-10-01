#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

struct Customer {
    int arrival;
    int departure;
    int id;
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    if (!(cin >> n)) return 0;

    vector<Customer> customers(n);
    for (int i = 0; i < n; i++) {
        cin >> customers[i].arrival >> customers[i].departure;
        customers[i].id = i;
    }
    sort(customers.begin(), customers.end(), [](const Customer& a, const Customer& b) {
        return a.arrival < b.arrival;
    });
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

    vector<int> ans(n);
    int next_room = 1;

    for (int i = 0; i < n; i++) {
        int room_num;
        if (!pq.empty() && pq.top().first < customers[i].arrival) {
            room_num = pq.top().second;
            pq.pop();
        } else {
            room_num = next_room++;
        }
        
        pq.push({customers[i].departure, room_num});
        ans[customers[i].id] = room_num;
    }
    cout << next_room - 1 << "\n";
    
    for (int i = 0; i < n; i++) {
        cout << ans[i] << (i == n - 1 ? "" : " ");
    }
    cout << "\n";

    return 0;
}