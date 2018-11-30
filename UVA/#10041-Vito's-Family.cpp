#include <bits/stdc++.h>
#define all(x) x.begin(), x.end()
const int INF = (1 << 30);
using namespace std;

void dance() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
}

int main() {
#ifndef ONLINE_JUDGE
    clock_t _begin = clock();
#endif
    dance();
    int t;
    cin >> t;
    while(t--) {
        int n;
        cin >> n;
        vector<int> p(n);
        for(int i = 0; i < n; i++)
            cin >> p[i];
        int res, best = INF;
        for(int i = 0; i < n; i++) {
            res = 0;
            for(int j = 0; j < n; j++)
                res += abs(p[i] - p[j]);
            best = min(res, best);
        }
        cout << best << endl;
    }

#ifndef ONLINE_JUDGE
    printf("\n>>Time : %.9f sec\n", (double) (clock() - _begin) / CLOCKS_PER_SEC);
#endif
}
