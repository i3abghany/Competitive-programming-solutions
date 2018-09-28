#include <bits/stdc++.h>

using namespace std; 

int row[8], a, b, n, L;

bool can_be_placed(int r, int c) {
    for(int i = 0; i < c; i++)
        if(row[i] == r || (abs(row[i] - r) == abs(i - c))) return false;
    return true;
}

void solve(int c) {
    if(c == 8 && row[b] == a) {
        printf("%2d      %d", ++L, row[0] + 1);
        for (int j = 1; j < 8; j++) printf(" %d", row[j] + 1);
        printf("\n");
    }
    for(int i = 0; i < 8; i++) {
        if(can_be_placed(i, c)) {
            row[c] = i;
            solve(c + 1);
        }
    }
}

int main() {
    cin >> n;
    L = 0;
    while(n--) {
        cin >> a >> b;
        a--; b--;
        printf("SOLN       COLUMN\n");
        printf(" #      1 2 3 4 5 6 7 8\n\n");
        solve(0);
        if(n) cout << endl;
    }

}
