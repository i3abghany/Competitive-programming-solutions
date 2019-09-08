#include <iostream>
#include <vector>

const std::string path = "@IEHOVA#";
constexpr std::size_t max_d = 10;

int n, m;
char arr[max_d][max_d];


bool valid(int r, int c, int curr) {
    return !(r >= n || r < 0 || c >= m || c < 0 || path[curr] != arr[r][c]);
}

void dfs(int r, int c, int curr_idx) {
    if(!valid(r, c, curr_idx) || curr_idx == path.length() - 1) return;

    if(arr[r - 1][c] == path[curr_idx + 1]) {
        std::cout << "forth";
        if(path[curr_idx + 1] != '#') std::cout << ' ';
        dfs(r - 1, c, curr_idx + 1);
    }

    if(arr[r][c + 1] == path[curr_idx + 1]) {
        std::cout << "right";
        if(path[curr_idx + 1] != '#') std::cout << ' ';
        dfs(r, c + 1, curr_idx + 1);
    }

    if(arr[r][c - 1] == path[curr_idx + 1]) {
        std::cout << "left";
        if(path[curr_idx + 1] != '#') std::cout << ' ';
        dfs(r, c - 1, curr_idx + 1);
    }
}

int main() {
    int tc; std::cin >> tc;
    while(tc--) {
        std::cin >> n >> m;
        std::pair<int, int> st;
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                std::cin >> arr[i][j];
                if(arr[i][j] == '@') st = {i, j};
            }
        }
        dfs(st.first, st.second, 0);
        std::cout << std::endl;
    }
    return 0;
}
