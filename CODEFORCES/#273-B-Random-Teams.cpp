#include <bits/stdc++.h>

using namespace std;

int main() {
	long long n, m, mn, mx;
	cin >> n >> m;
	mx = (n - m + 1) * (n - m) / 2;
	mn = (m * (n/m) * (n / m - 1) / 2) + ((n/m) * (n%m));
	cout << mn << " " << mx;
}
