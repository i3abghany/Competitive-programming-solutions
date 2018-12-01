#include <bits/stdc++.h>

#define all(x) x.begin(), x.end()

const int INF = (1 << 30);

using namespace std;

void dance() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
}

long long poww(long long base, int exp) {
    long long result = 1;
    for (;;) {
        if (exp & 1)
            result *= base;
        exp >>= 1;
        if (!exp)
            break;
        base *= base;
    }
    return result;
}

int main() {
    long long int n, res;
    vector<long long> dft;
    for(int i = 0; i <= 32; i++) {
        for(int j = 0; j <= 32; j++) {
            long long x = poww(2, i) * poww(3, j);
            if(x <= 1LL << 35) dft.push_back(x);
        }
    }
    sort(all(dft));
    int k;
    while(cin >> k && k) cout << *lower_bound(all(dft), k) << endl;
}
