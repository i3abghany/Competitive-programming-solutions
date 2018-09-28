#include <bits/stdc++.h>

using namespace std;

int grid[10][10],  n, res;
int col[10] = {0}, dL[20] = {0}, dR[20] = {0};

bool can_be_placed(int r, int c) {
    if(!col[c] && !dL[r+c] && !dR[r-c+7]) return true;
    return false;
}
 
void solve(int r, int s) {
    if(r == 8) {
        res = max(res, s);
        return;
    }
    for(int i = 0; i < 8; ++i) {
        if(can_be_placed(r, i)) {
            col[i] = 1;
            dL[i+r] = 1;
            dR[r-i+7] = 1;
            solve(r+1, s+grid[r][i]);
            col[i] = 0;
            dL[i+r] = 0;
            dR[r-i+7] = 0;
        }
    }
}

int main() {
    cin >> n;
    while(n--) {
        for(int i = 0; i < 8; i++) {
            for(int j = 0; j < 8; j++)
                scanf("%d", &grid[i][j]);
        }
        res = 0;
        solve(0, 0);
        cout << setw(5) << res << endl;
    }
}
