#include <bits/stdc++.h>

using namespace std;
#define maxN 10000010
#define pb push_back
int pr[46341];
vector<int> p;
vector<int> vv;

void seive() {
	pr[0] = 1;
	pr[1] = 1;
	for(int i = 2; i < 46341; ++i) {
		if(pr[i] == 0) {
			for(int j = i * 2; j < 46341; j += i) {
			    pr[j] = 1;
			}
			vv.pb(i);
		}
 	}
}

void solve(int n) {
	p.clear();
	if(n < 0) {
		p.pb(-1);
		n = abs(n);
	}
	for(int i = 0; i < vv.size(); i++) {
		while(n%vv[i] == 0) {
			p.pb(vv[i]);
			n /= vv[i];
		}
	}
	if(n != 1) p.pb(n);
}


int main() {
	memset(pr, 0, sizeof(pr));
	seive();
	int n;
	while(cin >> n && n) {
		cout << n << " = ";
		solve(n);
		int z = 0;
		for(auto ee : p) {
			z++;
			cout << ee;
			if(z < p.size()) cout << " x ";
			
		}
		cout << endl;
		p.clear();
	}
	return 0;
}
