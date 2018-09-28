#include <bits/stdc++.h>

using namespace std;

long long int g(int x) {
	long long cnt = 0, i;
	for(i = 1; i*i < x; i++) {
		if(x % i == 0) {
			cnt += 2;
		}
	}
	if(i*i == x) cnt++;
	return cnt;
}
 
int main() {
	long long int U, L, TC;
	cin >> TC;
	while(TC--) {
		cin >> U >> L;
		long long int d = 0, maxN = U;
		for(int i = U; i <= L; i++) {
			d = max(d, g(i));
			maxN = g(i) > g(maxN) ? i : maxN;
		}
		printf("Between %llu and %llu, %llu has a maximum of %llu divisors.\n", U, L, maxN, d);
	}
}
