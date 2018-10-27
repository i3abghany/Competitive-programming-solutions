#include <bits/stdc++.h>


using namespace std;

int main() {
	//freopen("inp.txt", "r", stdin);
	//freopen("out.txt", "w", stdout);
	int n, m, t;
	cin >> t;
	while(t--) {
		cin >> n >> m;
		while(n % 3 != 0) n--;
		while(m % 3 != 0) m--;
		cout << (n * m) / 9 << endl;
	}
	
}


