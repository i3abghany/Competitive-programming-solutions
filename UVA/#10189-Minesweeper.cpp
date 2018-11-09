#include <bits/stdc++.h>

using namespace std;

char grid[105][105];
int dx[] = {-1, 0, 1, -1, 1, -1, 0, 1};
int dy[] = {-1, -1, -1, 0, 0, 1, 1, 1};
int n, m, c = 0;

bool inline valid(int r, int c) {
    return (r < n && c < m && r >= 0 && c >= 0);
}

void inline init() {
    for (int i = 0; i <= 104; i++) {
        for (int j = 0; j <= 104; j++) {
            grid[i][j] = '.';
        }
    }
}

int main() {
#ifdef ONLINE_JUDGE
    ios_base::sync_with_stdio(0);
    cin.tie(nullptr);
#endif
    cin >> n >> m;
    while(true) {
        init();
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= m; j++) {
                cin >> grid[i][j];
            }
        }

        for(int i = 1; i <= n; i++) {
            for(int j = 1; j <= m; j++) {
                if(grid[i][j] == '*') continue;
                int cnt = 0;
                for(int xx = -1; xx < 2; xx++) {
                    for(int yy = -1; yy < 2; yy++) {
                        if(grid[i + xx][j + yy] == '*')
                            cnt++;
                    }
                }
                grid[i][j] = (char)cnt + '0';
            }
        }
        cout << "Field #" << ++c << ":" << endl;
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= m; j++) {
                cout << grid[i][j];
            }
            cout << endl;
        }
        if(cin >> n >> m && (n || m)) cout << endl;
        else break;
    }
}