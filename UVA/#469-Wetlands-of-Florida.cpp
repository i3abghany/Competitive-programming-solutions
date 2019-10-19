#include <iostream>
#include <cstring>
#include <vector>
#include <sstream>

using namespace std;
char mp[128][128];
bool vis[128][128];
int dx[] = {1, 1, 1, 0, 0, 0, -1, -1, -1};
int dy[] = {1, -1, 0, 1, -1, 0, 1, -1, 0};
int N, M;

int cnt;

void dfs(int r, int c) {
    if(r >= N || c >= M || c < 0 || r < 0 || vis[r][c] || mp[r][c] == 'L') return;
    vis[r][c] = true, cnt++;
    for(int d = 0; d < 8; d++) {
        dfs(r + dx[d], c + dy[d]);
    }
}


// handling only one test case at a time, because of the tedious input handling.
// tested on uDebug and passed the tests.
int main() {
    string lin;
    int lin_num = 0;
    while (getline(cin, lin) && isalpha(lin[0])) {
        for (int i = 0; i < lin.size(); i++) {
            mp[lin_num][i] = lin[i];
            if (!i) M = lin.size();
        }
        ++lin_num;
    }
    N = lin_num - 1;

    istringstream iss(lin);
    int x, y;
    iss >> x >> y;
    dfs(x - 1, y - 1);
    cout << cnt << '\n';
    while (cin >> x >> y) {
        memset(vis, 0, sizeof vis);
        cnt = 0;
        dfs(x - 1, y - 1);
        cout << cnt << '\n';
    }
    return 0;
}
