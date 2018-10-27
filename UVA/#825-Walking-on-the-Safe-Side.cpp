#include <bits/stdc++.h>

using namespace std;

char grid[105][105];
int dp[200][200];
int n, m;
void dance() {
    ios_base::sync_with_stdio(0);
    cin.tie(NULL); cout.tie(NULL);
}

bool valid(int r, int c) {
    if(r >= n || c >= m || r < 0 || c < 0)  return false;
    return true;
}

int solve(int r, int c) {
    if(grid[r][c] == 'x') return 0;
    if(!valid(r, c)) {
//        cout << r << " " << c << " are not valid" << endl;
        return 0;
    }
    if(r == n - 1 && c == m - 1) return 1;
    if(dp[r][c] != -1) return dp[r][c];
    return dp[r][c] = solve(r, c + 1) + solve(r + 1, c);
}

int main() {
    dance();
    int t, x, y, C = 0;
    string lin;
    cin >> t;
    while(t--) {
        if(C++) cout << endl;
        cin >> n >> m;
        memset(dp, -1, sizeof dp);
        for (int i = 0; i < n; ++i)
            for (int j = 0; j < m; ++j)
                grid[i][j] = '.';
            getline(cin, lin);
        for(int i = 0; i < n; i++) {
            getline(cin, lin);
            stringstream c(lin);
            c >> x;
            while (c >> y) grid[x - 1][y - 1] = 'x';
        }
        cout << solve(0, 0) << endl;
    }


    return 0;
}