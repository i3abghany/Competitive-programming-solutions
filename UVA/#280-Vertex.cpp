#include <bits/stdc++.h>

using namespace std;

vector<vector<int>> adj_list;
vector<bool> vis;

void dfs(int n) {
	if(vis[n]) return;
	vis[n] = true;
	for(vector<int>::size_type i = 0; i < adj_list[n].size(); i++) {
		dfs(adj_list[n][i]);
	}
}

int main() {
	int N;
	while(cin >> N && N) {
		adj_list.assign(N + 1, vector<int>());
		int v;
		while(cin >> v && v) {
			int u;
			while(cin >> u && u) {
				adj_list[v].push_back(u);
			}
		}
		int c;
		cin >> c;
		while(c--) {
			vis.clear();
			vis.assign(N + 1, false);
			int cnt = 0;
			int v; cin >> v;
			for(vector<int>::size_type i = 0; i < adj_list[v].size(); i++) {
				dfs(adj_list[v][i]);
			}
			for(int i = 1; i <= N; i++) if(vis[i]) ++cnt;
			cout << N - cnt << ' ';
			for(int i = 1; i <= N; i++) if(!vis[i]) cout << i << ' ';
			cout << '\n';
		}
	}

}
