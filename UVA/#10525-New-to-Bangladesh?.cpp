#include <bits/stdc++.h>

using namespace std;

const int N = 150;
const long long OO = 10000000000000;

long long int f[N][N];
long long int t[N][N];


int main() {
//    freopen("C:\\Users\\Mohamed\\CLionProjects\\UVA\\input.txt","r",stdin);
//    freopen("C:\\Users\\Mohamed\\CLionProjects\\UVA\\output.txt","w",stdout);
    long long int T, x, y, a, b, c, d;
    cin >> T;
    while(T--) {
        cin >> x >> y;
        for(int i = 0; i < x; i++) {
            for(int j = 0; j < x; j++) {
                if(i == j) f[i][j] = 0;
                else f[i][j] = t[i][j] = OO;
            }
        }
//        for(int i = 0; i < x; i++)
//            t[i][i] = f[i][i] = 0;
        for (int j = 0; j < y; ++j) {
            cin >> a >> b >> c >> d;
            if(c < t[a - 1][b - 1] || (c == t[a - 1][b - 1] && f[a - 1][b - 1] > d)) {
                t[a - 1][b - 1] = t[b - 1][a - 1] = c;
                f[a - 1][b - 1] = f[b - 1][a - 1] = d;
            }
        }
        for (int k = 0; k < x; ++k) {
            for (int i = 0; i < x; ++i) {
                for (int j = 0; j < x; ++j) {
                    if(t[i][k] + t[k][j] < t[i][j] || (t[i][j] == t[i][k] + t[k][j] && f[i][j] > f[i][k] + f[k][j])) {
                        t[i][j] = t[j][i] = t[i][k] + t[k][j];
                        f[i][j] = f[j][i] = f[i][k] + f[k][j];
                    }
                }
            }
        }
        int q, T1, T2;
        cin >> q;

        for(int i = 0; i < q; i++) {
            cin >> T1 >> T2;
//            T1--; T2--;
            if(f[T1 - 1][T2 - 1] != OO)
                printf("Distance and time to reach destination is %lld & %lld.\n", f[T1 - 1][T2 - 1], t[T1 - 1][T2 - 1]);
            else printf("No Path.\n");
        }
        if(T) printf("\n");
    }
}
