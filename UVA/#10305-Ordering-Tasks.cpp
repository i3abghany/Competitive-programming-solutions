#include <iostream>
#include <algorithm>
#include <set>
#include <vector>

int n, m;
std::vector<std::set<int>> adj;
std::vector<int> res;
std::vector<bool> vis;

bool valid(int r) {
    return r >= 1 && r <= n && !vis[r];
}

void dfs(int d) {
    if(!valid(d)) return;
    vis[d] = true;
    for(auto el : adj[d]) {
        dfs(el);
    }
    res.push_back(d);
}

int main(const int argc, const char* argv[]) {
    while(scanf("%d%d", &n, &m) == 2 && (n || m)) {
        adj.clear(), vis.clear(), res.clear();
        adj.resize(n + 1), vis.assign(n + 1, false);
        std::vector<int> indeg(n + 1, 0);
        for (int i = 0; i < m; i++) {
            int u, v;
            scanf("%d%d", &u, &v);
            if(adj[u].find(v) == std::end(adj[u])) {
                ++indeg[v];
                adj[u].insert(v);
            }
        }
        for (int i = 1; i <= n; i++) {
            if (indeg[i] == 0) {
                if (!vis[i]) {
                    dfs(i);
                }
            }
        }
        std::reverse(res.begin(), res.end());
        for (int i = 0; i < res.size(); i++) {
            printf("%d", res[i]);
            if(i != res.size() - 1) printf(" ");
        }
        puts("");
    }
    return 0;
}
