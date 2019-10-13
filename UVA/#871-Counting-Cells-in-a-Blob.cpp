#include <iostream>
#include <vector>
#include <limits>

std::vector<std::string> mp;
int curr;

void dfs(int r, int c) {
    if(r >= mp.size() || r < 0 || c >= mp[r].size() || c < 0) return;
    if(mp[r][c] == '0') return;

    mp[r][c] = '0'; curr++;
    dfs(r + 1, c), dfs(r - 1, c), dfs(r, c + 1), dfs(r, c - 1),
    dfs(r - 1, c - 1), dfs(r - 1, c + 1), dfs(r + 1, c - 1), dfs(r + 1, c + 1);
}

int main() {
    int tc; bool fr = true;
    scanf("%d", &tc);
    while (tc--) {
        if(fr) {
            std::cin.ignore();
            std::cin.ignore();
            fr = false;
        }
        mp.clear();
        std::string s;
        while (std::getline(std::cin, s) && !s.empty()) {
            mp.push_back(s);
        }
        int mx = std::numeric_limits<int>::min();

        for(int i = 0; i < mp.size(); i++) {
            for (int j = 0; j < mp[i].size(); j++) {
                if(mp[i][j] != '0') {
                    curr = 0;
                    dfs(i, j);
                    mx = std::max(curr, mx);
                }
            }
        }
        if(mx == std::numeric_limits<int>::min()) mx = 0;
        std::cout << mx << std::endl;
        if(tc) std::cout << std::endl;
    }
}
