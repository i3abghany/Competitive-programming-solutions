#include <bits/stdc++.h>

using namespace std;

int main() {
//	freopen("inp.txt", "r", stdin);
//	freopen("out.txt", "w", stdout);
	int n, m, x, y, t;
	cin >> t;
	while(t--) {
		cin >> n;
		n *= 315;
		n += 36962;
		cout << abs((n % 100 - n % 10) / 10) << endl;
	}
}
