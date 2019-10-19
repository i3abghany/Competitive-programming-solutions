#include <iostream>
#include <cstring>
#include <set>
#include <vector>

std::vector<std::set<int>> adj;
bool vis[26];

void dfs(int n) {
    if(vis[n]) return;
    vis[n] = true;
    for(auto l : adj[n]) {
        dfs(l);
    }
}

int main() {
    int tc;
    std::cin >> tc;
    for (int kase = 1; kase <= tc; kase++) {
        memset(vis, 0, sizeof vis);
        if(kase == 1) std::cin.ignore();
        char c; std::cin >> c;
        std::cin.ignore();
        adj.clear();
        adj.resize(c - 'A' + 1);
        std::string s;
        while(std::getline(std::cin, s) && !s.empty()) {
            if(s[0] == s[1]) continue;
            adj[s[0] - 'A'].insert(s[1] - 'A');
            adj[s[1] - 'A'].insert(s[0] - 'A');
        }
        int cnt = 0;
        for(int i = 0; i < (c - 'A' + 1); i++) {
            if(!vis[i]) {
                dfs(i);
                cnt++;
            }
        }
        std::cout << cnt << '\n';
        if(kase != tc) std::cout << '\n';
    }
    return 0;
}
