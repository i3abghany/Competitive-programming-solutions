#include <iostream>
#include <vector>
#include <memory.h>

int ans = 0;
int w, n;

std::vector<std::vector<int>> mp;
int dp[1000][1000];

bool valid(int r, int c) {
    return r < w && r >= 0 && c < n && c >= 0
           && mp[r][c] != -1;
}

int sol(int r, int c) {
    if (!valid(r, c)) return 0;
    if (dp[r][c] != -1) return dp[r][c];
    if (r == w - 1 && c == n - 1) return 1;
    return dp[r][c] = sol(r + 1, c) + sol(r, c + 1);
}

int main() {
    int tc; std::cin >> tc;
    while(tc--) {
        std::cin.get();
        std::cin >> w >> n;
        mp.clear();
        mp.resize(w, std::vector<int>(n, 1)); // 1 means safe.
        memset(dp, -1, sizeof(dp));
        for(int i = 0; i < w; i++) {
            int curr_street;
            std::cin >> curr_street;
            --curr_street;
            std::string s; std::getline(std::cin, s);
            std::istringstream ss(s);
            int x;
            while(ss >> x) {
                --x;
                mp[curr_street][x] = -1;
            }
        }
        std::cout << sol(0, 0) << '\n';
        if(tc) std::cout << '\n';
    }
    return 0;
}
