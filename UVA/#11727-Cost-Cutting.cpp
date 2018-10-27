#include <bits/stdc++.h>

using namespace std;

int a[3];

int main() {
//	freopen("inp.txt", "r", stdin);
//	freopen("out.txt", "w", stdout);
	int n, t = 0;
	cin >> n;
	while(n--) {
		cin >> a[0] >> a[1] >> a[2];
		sort(a, a + 3);
		cout << "Case " << ++t << ": " << a[1] <<endl;
	}
}
