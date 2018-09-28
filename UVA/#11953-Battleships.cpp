#include <bits/stdc++.h>

using namespace std;

const int N = 105;

char grid[N][N];
bool vis[N][N];

int dx[] = {0, 0, 1, -1};
int dy[] = {1, -1, 0, 0};


int n;

void solve(int x, int y) {
  if(x < 0 || y < 0 || y >= n || x >= n) return;
  if(grid[x][y] == '.') return;
  grid[x][y] = '.';
  for(int i = 0; i < 4; i++) {
    int nx = (x + dx[i]); int ny = y + dy[i];
    solve(nx, ny);
  }

}

int main() {
  int T;
  cin >> T;
  for(int Z = 1; Z <= T; Z++) {
    cin >> n;
    for(int i = 0; i < n; i++) cin >> grid[i];
    int ans = 0;
    for(int i = 0; i < n; i++) {
      for(int j = 0; j < n; j++) {
        if(grid[i][j] == 'x') ans++, solve(i, j);
      }
    }
    for(int i = 0; i < n; i++) {
      for(int j = 0; j < n; j++) grid[i][j] = 0;
    }
    cout << "Case " << Z << ": " << ans << endl;
    ans = 0;
  }
}
