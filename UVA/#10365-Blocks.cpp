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

    int n;
    cin >> n;
    for( ; n-- ; ) {
        int N; cin >> N;
        int best = INF;
        for(int i = 1; i * i <= N; i++) {
            if(N % i == 0) {
                int t = N / i;
                for(int j = 1; j * j <= t; j++) {
                    if(t % j == 0)
                      best = min(best, 2 *(i * j + t + i * t / j));
                }
            }
        }
        cout << best << endl;
    }
#ifndef ONLINE_JUDGE
    printf("\n>>Time : %.9f sec\n", (double) (clock() - _begin) / CLOCKS_PER_SEC);
#endif

}
