#include<iostream>
#include<vector>

using namespace std;

class DSU{
    private:
        vector<int> parent, size;
        int largets_size = 0;
        int tot_components;
    public:
        DSU(int n){
            parent.resize(n);
            size.resize(n, 1);
            for(int i = 0; i < n ;i++){
                parent[i] = i;
            }
            this->tot_components = n;
        }
        int UParent(int x){
            if(parent[x] != x){
                return parent[x] = UParent(parent[x]);
            }
            return parent[x];
        }
        void Union(int x, int y){
            int px = this->UParent(x);
            int py = this->UParent(y);
            if(px == py)return;
            if(size[px] < size[py]){
                parent[px] = py;
                size[py] += size[px];
                this->largets_size = max(this->largets_size, size[py]);
            }
            else{
                parent[py] = px;
                size[px] += size[py];
                this->largets_size = max(this->largets_size, size[px]);
            }
            this->tot_components--;
        }
        int getLargestSize(){
            return this->largets_size;
        }
        int getComponents(){
            return this->tot_components;
        }
};

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n, m;
    if(!(cin >> n >> m))return 0;
    DSU dsu(n);
    for(int i = 0; i < m; i++){
        int u, v;
        if(!(cin >> u >> v))return 0;
        dsu.Union(u-1, v-1);
        cout << dsu.getComponents() << " " << dsu.getLargestSize() << "\n";
    }
    return 0;
}