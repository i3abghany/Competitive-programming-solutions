#include <bits/stdc++.h>

using namespace std;

int c(int n, int k) {
	int res = 1;
	k = min(k, n - k);
	for(int i = 1; i <= k; i++) res = res * (n - i + 1) / i;
	return res;
}

int main() {
	cout << fixed;
	cout << setprecision(12);
	string s1, s2;
	cin >> s1 >> s2;
	int c1 = 0, c2 = 0;
	size_t unknown = count(s2.begin(), s2.end(), '?');
	for(int i = 0; i < s1.size(); i++) {
		if(s1[i] == '+') c1++;
		else c1--;
	}
	for(int i = 0; i < s2.size(); i++) {
		if(s2[i] == '+') c2++;
		else if(s2[i] == '-') c2--;
	}
	if(unknown == 0) {
		if(c1 == c2) cout << 1.0 * 1;
		else cout << 0 * 1.0;
	} else {
		int CASES = pow(2, unknown);
		int DIFF = abs(c1 - c2);
		if(DIFF > unknown) cout << "0.00000000000";
		else cout << 1.0 * c(unknown, (unknown + DIFF) / 2) / CASES;
	}
}
