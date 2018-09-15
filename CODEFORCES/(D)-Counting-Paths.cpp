#include <bits/stdc++.h>
// #include <boost/spirit.hpp>

#define ll long long int
#define F first
#define S second
#define mp make_pair
#define pb push_back
#define all(x) x.begin(), x.end()

const int MOD = 1000000007;
const int maxN = 1000002;
//const double pi = boost::math::constants::pi<double>();

using namespace std;

ll factorial[maxN];
ll inv[maxN];

ll power(ll b, ll p) {
	if(p == 0) return 1;
	if(p % 2 == 0) return power(b * b % MOD, p/2);
	else return b * power(b, p - 1) % MOD;
}

void init() {
	factorial[0] = inv[0] = 1;
	for(int i = 1; i < maxN; i++) {
		factorial[i] = factorial[i - 1] * i % MOD;
		inv[i] = power(factorial[i], MOD - 2);
	}
}

ll nCr(int n, int r) {
	return factorial[n] * inv[r] % MOD * inv[n - r] % MOD;
}

int main() {
	init();
	int T, a, b;
	scanf("%d", &T);
	while(T--) {
		scanf("%d %d", &a, &b);
		if(b - a == 1) printf("2");  
		else printf("%I64d\n", 2 * nCr(a - 1, b) % MOD);
	}
    return 0;
}
