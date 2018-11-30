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
    int t, TC = 1;
    while(cin >> t && t) {
        vector<int> p(t);
        for(int i = 0; i < t; i++)
            cin >> p[i];
        int q; cin >> q;
        cout << "Case " << TC++ << ":" << endl;
        int Query;
        for(int i = 0; i < q; i++) {
            cin >> Query;
            int mn = INF;
            int ans = INF;
            for(int k = 0; k < t; k++) {
                for(int j = 0; j < t; j++) {
                    if(k == j) continue;
                    int sum = p[k] + p[j];
                    if(abs(Query - sum) < mn) {
                        mn = abs(Query - sum);
                        ans = sum;
                    }
                }
            }
            cout << "Closest sum to " << Query << " is " << ans << "." << endl;

        }
    }

#ifndef ONLINE_JUDGE
    printf("\n>>Time : %.9f sec\n", (double) (clock() - _begin) / CLOCKS_PER_SEC);
#endif
}
