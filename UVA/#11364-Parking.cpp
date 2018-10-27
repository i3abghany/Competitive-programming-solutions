#include <bits/stdc++.h>

using namespace std;

int a[25];

int main() {
//	freopen("inp.txt", "r", stdin);
//	freopen("out.txt", "w", stdout);
	int n, t;
	cin >> t;
	while(t--) {
		cin >> n;
		for(int i = 0; i < n; i++)
			cin >> a[i];
		int mn = *min_element(a, a + n);
		int mx = *max_element(a, a + n);
		cout << 2 * (mx - mn) << endl;
	}
}
