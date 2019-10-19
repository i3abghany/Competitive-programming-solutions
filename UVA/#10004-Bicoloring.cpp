#include <iostream>
#include <cstring>
#include <vector>
#include <queue>

using namespace std;

vector<vector<int>> adj;

int main() {
    freopen("inp.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
    int n;
    while(cin >> n && n != 0) {
        adj.clear();
        int m; cin >> m;
        adj.resize(n);
        int u, v;
        for(int i = 0; i < m; i++) {
            cin >> u >> v;
            adj[u].push_back(v);
        }
        int curr_color = 0;
        int color[n];
        memset(color, -1, sizeof color);
        queue<int> Q;
        Q.push(0);
        color[0] = curr_color;
        while(!Q.empty()) {
            auto t = Q.front(); Q.pop();
            curr_color = !curr_color;
            for(auto neig : adj[t]) {
                if(color[neig] == color[t]) {
                    cout << "NOT BICOLORABLE.\n";
                    goto zz;
                } else {
                    color[neig] = curr_color;
                    Q.push(neig);
                }
            }
        }
        cout << "BICOLORABLE.\n";
        zz: ;
    }
    return 0;
}
