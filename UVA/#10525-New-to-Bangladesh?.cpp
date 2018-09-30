#include <bits/stdc++.h>

using namespace std;

const int N = 150;
const long long int OO = 1e12;

long long int f[N][N];
long long int t[N][N];

void init(int n) {
    for (int i = 0; i < n; ++i) {
        for(int j = 0; j < n; j++) {
            f[i][j] = f[j][i] = OO;
        }
        f[i][i] = 0;
    }
    for (int k = 0; k < n; ++k) {
        for (int i = 0; i < n; ++i) {
            t[k][i] = t[i][k] = OO;
        }
        f[k][k] = 0;
    }
}


int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
   // freopen("C:\\Users\\Mohamed\\CLionProjects\\UVA\\input.txt","r",stdin);
   // freopen("C:\\Users\\Mohamed\\CLionProjects\\UVA\\output.txt","w",stdout);
    long long int T, x, y, a, b, c, d;
    cin >> T;
    while(T--) {
        cin >> x >> y;
        init(x);
        for (int i = 0; i < y; ++i) {
            cin >> a >> b >> c >> d;
            if(t[a - 1][b - 1] > c || (c == t[a - 1][b - 1] && d < f[a - 1][b - 1])) {
                t[a - 1][b - 1] = t[b - 1][a - 1] = c;
                f[a - 1][b - 1] = f[b - 1][a - 1] = d;
            }
        }
        for (int k = 0; k < x; ++k) {
            for(int i = 0; i < x; ++i) {
                for(int j = 0; j < x; j++) {
                    if(t[i][j] > t[i][k] + t[k][j]) {
                        f[i][j] = f[i][k] + f[k][j];
                        t[i][j] = t[i][k] + t[k][j];
                    } else if(t[i][j] == t[i][k] + t[k][j] && f[i][j] > f[i][k] + f[k][j])
                        f[i][j] = f[i][k] + f[k][j];
                }
            }
        }
        int q, T1, T2;
        cin >> q;
        while(q--) {
            cin >> T1 >> T2;
            if(T1 == T2) cout << "Distance and time to reach destination is 0 & 0.\n";            
            else if(f[T1 - 1][T2 - 1] != OO)
                cout << "Distance and time to reach destination is " << f[T1-1][T2-1] << " & " << t[T1-1][T2-1] << ".\n";
            else cout << "No path.\n";
        }
        if(T) cout << endl;
    }
    return 0;
}
