#include <iostream>
#include <vector>
#include <limits>


std::vector<std::string> mp;

void dfs(int r, int c) {
    if(mp[r][c] != ' ' && mp[r][c] != '*') return;
    if(r >= mp.size() || r < 0 || c >= mp[r].size() || c < 0) return;

    mp[r][c] = '#';
    dfs(r + 1, c), dfs(r - 1, c), dfs(r, c + 1), dfs(r, c - 1);
}

int main() {
    int tc;
    scanf("%d", &tc);
    bool fr = true;
    while (tc--) {
        int r, c;
        r = c = std::numeric_limits<int>::max();
        if(fr) {
            fr = false;
            std::cin.ignore();
        }
        mp.clear();
        std::string s;
        while (std::getline(std::cin, s) && s[0] != '_') {
            mp.push_back(s);
            if (r != std::numeric_limits<int>::max()) continue;
            for (int i = 0; i < s.size(); i++) {
                if (mp.back()[i] == '*') {
                    r = mp.size() - 1;
                    c = i;
                    break;
                }
            }
        }
        dfs(r, c);
        for (auto &lin : mp) {
            for (auto &t : lin) {
                std::cout << t;
            }
            std::cout << std::endl;
        }
        std::cout << s;
        if(tc) std::cout << std::endl;
    }
}
