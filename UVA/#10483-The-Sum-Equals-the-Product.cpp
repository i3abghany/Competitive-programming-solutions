#include <iostream>
#include <stdio.h>
#include <vector>
#include <utility>
#include <algorithm>

using namespace std;

using ll = long long;

struct S {
    int s, a, b, c;
    S(int s_, int a_, int b_, int c_) : s{s_}, a{a_}, b{b_}, c{c_} {}

    bool operator<(const S& x) const {
        if(s != x.s) return s < x.s;
        return a < x.a;
    }
};


int main()
{
    int a, b, c;
    vector<S> ans;
    for(int i = 1; 3*i <= 25600; i++) {
        for(int j = i; j <= 25600; j++) {
            ll p = (ll)i*j;
            ll s = i+j;
            if(p <= 10000) continue;
            c = (s * 10000LL) / (p - 10000);
            s += c;
            if(s > 25600 || c < j) continue;
            if(i + j + c == (ll)i*j*c/10000) {
                bool f = true;
                for(auto x : ans) {
                    if(s == x.s) {
                        long long arr[3] = {x.a, x.b, x.c};
                        sort(arr, arr+3);
                        long long arr2[3] = {i, j, c};
                        sort(arr2, arr2+3);
                        for(int k = 0; k < 3; k++)
                            f &= (arr[k] != arr2[k]);
                    }
                }
                if(f) ans.push_back(S(s,i,j,c));
            }
        }
    }
    sort(ans.begin(), ans.end());
    int x, y, z, m;
    while(scanf("%d.%d %d.%d", &x, &y, &z, &m) == 4) {
        int n = x * 100 + y;
        int k = z * 100 + m;
        for(auto tt : ans) {
            if(tt.s >= n && tt.s <= k) {
                a = tt.a, b = tt.b, c = tt.c;
                printf("%d.%02d = %d.%.02d + %d.%02d + %d.%02d = %d.%.02d * %d.%02d * %d.%02d\n", tt.s/100, tt.s%100, a/100, a%100, b/100, b%100, c/100, c%100, a/100, a%100, b/100, b%100, c/100, c%100);
            }
        }
    }
    return 0;
}
