#include <stdio.h>

#define max(a, b) a > b ? a : b;

int LCS(int const *a, unsigned N, int const *b, unsigned M) {
    int L[N + 1][M + 1];
    for(int i = 0; i <= N; i++) L[i][0] = 0;
    for(int i = 0; i <= M; i++) L[0][i] = 0;

    for(int i = 1; i <= N; i++) {
        for(int j = 1; j <= M; j++) {
            if(a[i - 1] == b[j - 1]) {
                L[i][j] = L[i - 1][j - 1] + 1;
            } else L[i][j] = max(L[i - 1][j], L[i][j - 1]);
        }
    }
    return L[N][M];
}

int main() {
    freopen("inp.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
    unsigned N1, N2;
    unsigned c = 0;
    while(scanf("%u %u", &N1, &N2) == 2 && (N1 || N2)) {
        int tower1[N1];
        int tower2[N2];
        for (unsigned i = 0; i < N1; i++) scanf("%d", tower1 + i);
        for (unsigned i = 0; i < N2; i++) scanf("%d", tower2 + i);
        printf("Twin Towers #%d\n", ++c);
        printf("Number of Tiles : %d\n", LCS(tower1, N1, tower2, N2));
    }
    return 0;
}
