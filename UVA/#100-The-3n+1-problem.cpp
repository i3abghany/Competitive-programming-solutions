#include <bits/stdc++.h>

using namespace std;

int ser(int n) {
	int res = 0;
	while(n != 1) {
		if(n & 1) {
			n = 3 * n + 1;
			res++;
		} else {
			n /= 2;
			res++;
		}
	}
	return ++res;
}

int main() {
//	freopen("inp.txt", "r", stdin);
//	freopen("out.txt", "w", stdout);
	int a, b, res = 0;
	while(cin >> a >> b && (a || b)) {
		for(int i = min(a, b); i <= max(a, b); i++)
			res = max(res, ser(i));
		cout << a << " " << b << " " << res << endl;
		 
		res = 0;
	}
}
