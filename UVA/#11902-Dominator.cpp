#include <iostream>
#include <cstring>

constexpr size_t nax = 100;

bool adj[nax][nax];
bool dom[nax][nax];
bool vis[nax];

int n;

void dfs(int nn) {
    vis[nn] = true;
    for (int i = 0; i < n; i++) {
        if (adj[nn][i] && !vis[i]) {
            dfs(i);
        }
    }
}

int main() {
    int tc;
    std::cin >> tc;
    for (int kase = 1; kase <= tc; kase++) {
        std::cin >> n;
        memset(dom, 0, sizeof(dom));
        memset(adj, 0, sizeof(adj));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                std::cin >> adj[i][j];
            }
        }
        dom[0][0] = true;
        for (int curr = 1; curr < n; curr++) {
            memset(vis, 0, sizeof vis);
            dom[0][curr] = true;
            vis[curr] = true;
            dfs(0);
            for(int i = 0; i < n; i++) {
                if(!vis[i]) dom[curr][i] = true;
            }
            dom[curr][curr] = true;
        }

        memset(vis, false, sizeof(vis));
        dfs(0);

        std::cout << "Case " << kase << ":\n";
        for (int i = 0; i < n; i++) {
            for(int k = 0; k < 2 * n - 1; k++) {
                if(!k) std::cout << '+';
                std::cout << '-';
            }
            std::cout << "+\n";
            for (int j = 0; j < n; j++) {
                if(j == 0) std::cout << '|';
                std::cout << (dom[i][j] && vis[j] ? 'Y' : 'N') << '|';
            }
            std::cout << '\n';
        }

        for(int k = 0; k < 2 * n - 1; k++) {
            if(!k) std::cout << '+';
            std::cout << '-';
        }
        std::cout << '+';
        if(kase != tc) std::cout << '\n';
    }
    return 0;
}
