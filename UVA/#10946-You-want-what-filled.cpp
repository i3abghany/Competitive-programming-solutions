#include <iostream>
#include <algorithm>

int n, m;
char mp[1000][1000];
char curr_ch; int curr_score;

bool valid(int r, int c) {
    return r >= 0 && c >= 0 && r < n && c < m && mp[r][c] == curr_ch;
}

void dfs(int r, int c) {
    if(!valid(r,c)) return;

    mp[r][c] = '.';
    curr_score++;
    dfs(r + 1, c), dfs(r - 1, c), dfs(r, c + 1), dfs(r, c - 1);
}

int main(const int argc, const char* argv[]) {
    int cas = 0;
    while(scanf("%d%d", &n, &m) == 2 && (n || m)) {

        for (int i = 0; i < n; i++) {
            scanf("%s", mp[i]);
        }
        std::vector<std::pair<char, int>> holes;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (mp[i][j] == '.') continue;
                curr_ch = mp[i][j];
                dfs(i, j);
                holes.emplace_back(curr_ch, curr_score);
                curr_score = 0;
            }
        }

        std::sort(std::begin(holes), std::end(holes) ,[&](std::pair<char, int> &a, std::pair<char, int> &b) {
            if (a.second == b.second) return a.first < b.first;
            return a.second > b.second;
        });
        printf("Problem %d:\n", ++cas);
        for (int i = 0; i < holes.size(); i++) {
            printf("%c %d\n", holes[i].first, holes[i].second);
        }
    }
    return 0;
}
