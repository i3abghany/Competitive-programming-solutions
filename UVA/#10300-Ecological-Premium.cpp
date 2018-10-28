#include <bits/stdc++.h>

using ll = long long;

using namespace std;

int main() {   
	ios::sync_with_stdio(0);
	cin.tie(0);
    freopen("inp.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
	int t, z;
	cin >>t;
	while(t--) {
		int res = 0;
		cin >> z;
		while(z--) {
			int a, b, c;
			cin >> a >> b >> c;
			res += a * c;
		}
		cout << res << endl;
	}	
}
