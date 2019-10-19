#include <iostream>
#include <cstring>
#include <vector>
#include <queue>

using namespace std;

vector<vector<int>> adj;
vector<int> color;
vector<bool> vis;

bool dfs(int n) {
    for (auto neig : adj[n]) {
        if (!vis[neig]) {
            vis[neig] = true;
            color[neig] = !color[n];
            if (!dfs(neig)) return false;
        } else if (color[n] == color[neig]) return false;
    }
    return true;
}

int main() {
    int n;
    while (cin >> n && n != 0) {
        adj.clear();
        int m;
        cin >> m;
        adj.resize(n);
        int u, v;
        for (int i = 0; i < m; i++) {
            cin >> u >> v;
            adj[u].push_back(v);
        }
        int curr_color = 0;
        color.clear();
        vis.clear();
        color.assign(n, -1);
        vis.assign(n, false);
        color[0] = curr_color;
        if (dfs(0)) cout << "BICOLORABLE.\n";
        else cout << "NOT BICOLORABLE.\n";
    }
    return 0;
}
