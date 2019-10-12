#include <iostream>
#include <vector>
#include <algorithm>
#include <map>

char mp[1000][1000];
int n, m;
char curr;
bool valid(int r, int c) {
    return r < n && r >= 0 && c >= 0 && c < m && mp[r][c] == curr;
}

void dfs(int r, int c) {
    if(!valid(r,c)) return;

    mp[r][c] = '#';
    dfs(r + 1, c), dfs(r - 1, c), dfs(r, c + 1), dfs(r, c - 1);
}

int main(const int argc, const char* argv[]) {
    int TC; scanf("%d", &TC);
    for(int cc = 1; cc <= TC; cc++) {
        scanf("%d %d", &n, &m);
        for (int i = 0; i < n; i++) {
            scanf("%s", mp[i]);
        }
        std::map<char, int> langs;
        std::vector<std::pair<char, int>> langs_vec;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (langs.find(mp[i][j]) == std::end(langs)) langs[mp[i][j]] = 0;
            }
        }

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (mp[i][j] == '#') continue;
                curr = mp[i][j];
                dfs(i, j);
                ++langs[curr];
            }
        }

        langs_vec.assign(std::begin(langs), std::end(langs));

        std::sort(std::begin(langs_vec), std::end(langs_vec), [&](std::pair<char, int> &a, std::pair<char, int> &b) {
            if (a.second == b.second) return a.first < b.first;
            else return a.second > b.second;
        });

        printf("World #%d\n", cc);
        for(int i = 0; i < langs_vec.size(); i++) {
            printf("%c: %d\n", langs_vec[i].first, langs_vec[i].second);
        }
    }
    return 0;
}
