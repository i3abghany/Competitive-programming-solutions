#include <bits/stdc++.h>
#define ll long long

using namespace std;

const int N = 10;
int TT, n, m;

char grid[N][N];

int p[10];

int dx[] = {0, -1, 0};
int dy[] = {-1, 0, 1};

string s = "@IEHOVA#";

// void dfs(int v) {
//   vis[v] = 1;
//   if(grid[i][j] == '#') return;
//   for(auto e : adj[v]) {
//     if(!vis[e]) {
//       dfs(e);
//       // cnt++;
//     }
//   }
// }
//

void solve(int x, int y, int k) {
  if(x < 0 || y < 0 || x >= n || y >= m || grid[x][y] != s[k]) return;
  if(grid[x][y] == '#') {
    for(int i = 0; i < k; i++) {
      if(i) cout << " ";
      if(p[i] == 0) cout << "left";
      else if(p[i] == 1) cout << "forth";
      else if(p[i] == 2) cout << "right";
    }
    cout << endl;
    return;
  }
  for(int i = 0; i < 3; i++) {
    int nx = x + dx[i];
    int ny = y + dy[i];
    p[k] = i;
    solve(nx, ny, k + 1);
  }


}


void clr() {
  memset(p, 0, sizeof p);
}
int main() {
  ios_base::sync_with_stdio(0);
   cin >> TT;
   while(TT--) {
      clr();
      cin >> n >> m;
      for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
          cin >> grid[i][j];
        }
      }
      for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++)
          if(grid[i][j] == '@') {
            solve(i, j, 0);
          }
      }
   }

  return 0;
}
