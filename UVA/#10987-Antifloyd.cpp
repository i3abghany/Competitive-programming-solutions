#include <bits/stdc++.h>

using namespace std;

const int N = 120;
const int OO = 1e8;
int F[N][N];
int adj[N][N];

void floyd(int n) {
    for (int k = 0; k < n; ++k) {
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                if(F[i][j] > F[i][k] + F[k][j]) {
                    // It's said that the latencies are the shortest paths between computers
                    // so if we get a better path passing another computer or a path,
                    // it wouldn't be true for what is given.
                    cout << "Need better measurements." << endl;
                    return;
                }
                if(i == j || i == k)
                    continue;
                if(F[i][j] == F[i][k] + F[k][j])
                    // for minimizing the number of cables, we can delete the direct cables
                    // if there exist a taller one giving the same efficiency.
                    adj[i][j] = 0;
            }
        }
    }
    int c = 0;
    for(int i = 0; i < n; i++)
        for (int j = i; j < n; ++j)
            if(adj[i][j] == 1 && i != j) c++;
        printf("%d\n", c);
        for (int i = 0; i < n; ++i) {
        for(int j = i; j < n; j++) {
            if(adj[i][j] == 1 && i != j)
                printf("%d %d %d\n", i + 1, j + 1, F[i][j]);
        }
    }
    
}

void init(int n) {
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            if(i == j) F[i][i] = 0;
            else F[i][j] = OO;
        }
    }
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            adj[i][j] = 1;
        }
    }
}

int main() {
//    freopen("input.txt","r",stdin); freopen("output.txt","w",stdout);
    int T, cases = 1;
    cin >> T;
    while(T--) {
        int n;
        cin >> n;
        init(n);
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < i; j++) {
                cin >> F[i][j];
                F[j][i] = F[i][j];
            }
            F[i][i] = 0;
        }
        printf("Case #%d:\n", cases++);
        floyd(n);
        printf("\n");
        }
}
