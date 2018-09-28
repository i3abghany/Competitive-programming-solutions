#include <bits/stdc++.h>
#define ll long long

using namespace std;

const int N = 1001;
bool vis[N];
vector<int> adj[N];
double x[N], y[N];

void dfs(int v) {
  vis[v] = 1;
  for(auto e : adj[v]) {
    if(!vis[e]) {
      dfs(e);
      // cnt++;
    }
  }
}


void clr() {
  memset(vis, 0, sizeof(vis));
  for(int i = 0; i < N; i++) adj[i].clear();
  // memset(dist, 0, N*N);
}
int main() {
  int t, C;
  double u, v, d;
  cin >> t;
  for(int TTT = 0; TTT < t; TTT++) {
    clr();
    cin >> C >> d;
    for(int i = 0; i < C; ++i) {
      cin >> x[i] >> y[i];
    }
    for(int i = 0; i < C; i++) {
      for(int j = i + 1; j < C; j++) {
        if(hypot(abs(x[i] - x[j]), abs(y[i] - y[j])) <= d && i != j) {
          adj[i].push_back(j);
          adj[j].push_back(i);
        }
      }
    }
      int cnt = 0;
      for(int i = 0; i < C; i++) {
        if(!vis[i]) {
          cnt++;
          dfs(i);
        }
      }
      cout << "Case " << TTT + 1 << ": " << cnt << endl;
  }

  return 0;
}
