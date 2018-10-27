#include <bits/stdc++.h>

using namespace std;

int main() {
//	freopen("inp.txt", "r", stdin);
//	freopen("out.txt", "w", stdout);
	int n, m, x, y, t, i = 1;
	while(cin >> t && t) {
		cin >> n >> m;
		for(int i = 0; i < t; i++) {
			cin >> x >> y;
			if(x == n || y == m)
				cout << "divisa" << endl;
			else if(x > n && y > m)
				cout << "NE" << endl;
			else if(x > n && y < m)
				cout << "SE" << endl;
			else if(x < n && y > m)
				cout << "NO" << endl;
			else if(x < n && y < m)
				cout << "SO" << endl;
			else cout << "HA55555555" << endl;
		}
	}
}
