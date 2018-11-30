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
    string cmp[] = {"BCG",
                    "BGC",
                    "CBG",
                    "CGB",
                    "GBC",
                    "GCB"
    };
    int b[3][3];
    while(cin >> b[0][0]) {
        cin >> b[0][1] >> b[0][2];
        for(int i = 0; i < 3; i++)
            cin >> b[1][i];
        for(int i = 0; i < 3; i++)
            cin >> b[2][i];
        int curr, best = INF;
        string ans = cmp[0];
        for(int k = 0; k < 6; k++) {
            curr = 0;
            for(int i = 0; i < 3; i++){
                for(int j = 0; j < 3; j++) {
                    if(i == j) continue;
                    if(cmp[k][i] == 'B') curr += b[j][0];
                    else if(cmp[k][i] == 'C') curr += b[j][2];
                    else curr += b[j][1];
                }
            }
            if(curr < best) {
                best = curr;
                ans = cmp[k];
            }
        }
        cout << ans << " " << best << endl;
    }
    
#ifndef ONLINE_JUDGE
    printf("\n>>Time : %.9f sec\n", (double) (clock() - _begin) / CLOCKS_PER_SEC);
#endif
}
