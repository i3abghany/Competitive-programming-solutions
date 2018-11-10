#include <bits/stdc++.h>

using namespace std;

char grid[3][3];

inline pair<int, int> init() {
    pair<int, int> x(0, 0);
    for(int i = 0; i < 3; i++) {
        for(int j = 0; j < 3; j++) {
            cin >> grid[i][j];
            if(grid[i][j] == 'X')
                x.first++;
            if(grid[i][j] == 'O')
                x.second++;
        }
    }
    return x;
}

inline int is_there_someone_winning(char x) {
    for(int i = 0; i < 3; i++) {
        if((grid[i][0] == x && grid[i][1] == x && grid[i][2] == x))
            return 1;
    }
    for(int i = 0; i < 3; i++) {
        if((grid[0][i] == x && grid[1][i] == x && grid[2][i] == x))
            return 1;
    }
    if((grid[0][0] == x && grid[1][1] == x && grid[2][2] == x) || (grid[0][2] == x && grid[1][1] == x && grid[2][0] == x) )
        return 1;

    return 0;
}

int main() {
#ifdef ONLINE_JUDGE
    ios_base::sync_with_stdio(0);
    cin.tie(nullptr);
#endif
    int n;
    cin >> n;
    while (n--) {
        pair<int, int> x = init();
        if ((x.first == x.second && !is_there_someone_winning('X')) ||
            (x.first == x.second + 1 && !is_there_someone_winning('O'))) {
            cout << "yes" << endl;
            continue;
        } else {
            cout << "no" << endl;
            continue;
        }
    }
}

// gentlemen, it's a very sad thing to be nothing.
