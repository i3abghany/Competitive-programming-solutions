#include <bits/stdc++.h>

const double PI = 2*acos(0);

using namespace std;

void printPath(map<char, char> vis, char v) {
	if(vis[v] != v) printPath(vis, vis[v]);
	cout << v;
}

int main() {
	int T, a, b;
	map<char, vector<char>> adjList;	
	cin >> T;
	while(T--) {
		adjList.clear();
		cin >> a >> b;
		string s1, s2;
		for(int i = 0; i < a; i++) {
			cin >> s1 >> s2;
			adjList[s1[0]].push_back(s2[0]);
			adjList[s2[0]].push_back(s1[0]);
		}
		for(int i = 0; i < b; i++) {
			cin >> s1 >> s2;
			queue<char> q;
			map<char, char> vis;
			vis[s1[0]] = s1[0];
			q.push(s1[0]);
			while(!q.empty() && !vis.count(s2[0])) {
				char u = q.front();
				q.pop();
				for(int j = 0; j < adjList[u].size(); ++j) {
					const char v = adjList[u][j];
					if(!vis.count(v)) {
						vis[v] = u;
						q.push(v);
					}
				}
			}
			printPath(vis, s2[0]);
			cout << endl;
		}
		if(T) cout << "\n";
	}
}
