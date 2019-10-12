#include <iostream>
#include <vector>
#include <sstream>
#include <iomanip>

std::string mp[1000][1000];
bool vis[1000][1000];
int n, m;

bool valid(int r, int c, std::string &k) {
    return r < n && r >= 0 && c >= 0 && c < m && mp[r][c] == k && !vis[r][c];
}

int dx[] = {1, 1, 1, -1, -1, -1, 0, 0, 0};
int dy[] = {0, 1, -1, 0, 1, -1, 0, 1, -1};

void dfs(int r, int c, std::string &curr_char, int curr_tree) {
    if (!valid(r, c, curr_char)) return;

    vis[r][c] = true;
    mp[r][c] = std::to_string(curr_tree);
    for (int i = 0; i < 8; i++) {
        int new_r = r + dx[i], new_c = c + dy[i];
        dfs(new_r, new_c, curr_char, curr_tree);
    }
}

int main(const int argc, const char* argv[]) {
    while (std::cin.peek() != std::char_traits<char>::eof()) {
        std::string lin;
        int line_number = 0;
        while (std::getline(std::cin, lin) && lin != "%") {
            std::istringstream iss(lin);
            char c;
            int i = 0;
            while (iss >> c) {
                mp[line_number][i++] = c;
            }
            m = i;
            line_number++;
        }
        n = line_number;
        int k = 1;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (!vis[i][j]) {
                    dfs(i, j, mp[i][j], k);
                    k++;
                }
            }
        }
    }
    
    // did not handle the output, tested against udebug.
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            std::cout << std::setw(3) << mp[i][j] << ' ';
        }
        std::cout << std::endl;
    }
    return 0;
}
