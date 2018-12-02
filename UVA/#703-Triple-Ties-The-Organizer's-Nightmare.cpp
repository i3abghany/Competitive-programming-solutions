#include <bits/stdc++.h>

using namespace std;

void fopen() {
    freopen("C:\\Users\\Mohamed\\CLionProjects\\Codeforces\\in.txt", "r", stdin);
    freopen("C:\\Users\\Mohamed\\CLionProjects\\Codeforces\\out.txt", "w", stdout);
}

void dance() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
}

int arr[1004][1004];

int main() {
//    fopen();
    int n;
    while(cin >> n) {
        for(int i = 0; i < n; i++)
            for(int j = 0; j < n; j++)
                cin >> arr[i][j]
        vector<int> a, b, c;
        int ans = 0;
        for ( int i = 0; i < n; i++)
            for (int j =  0; j < n; j++)
                for (int k = 0; k < n; k++) {
                    if(((i > j && j > k) || (i < j && j < k)) && (arr[i][j] == 1 && arr[j][k] == 1 && arr[k][i] == 1)) {
                        ans++;
                        a.push_back(i);
                        b.push_back(j);
                        c.push_back(k);
                    }
                    else if((i < j&& j < k)
                            && arr[i][j] == 0
                            && arr[j][k] == 0
                            && arr[i][k] == 0
                            && arr[j][i] == 0
                            && arr[k][i] == 0
                            && arr[k][j] == 0) {
                        ans++;
                        a.push_back(i);
                        b.push_back(j);
                        c.push_back(k);
                    }
                }
        printf("%d\n", ans);
        for(int i = 0; i < a.size(); i++)
            printf("%d %d %d\n", a[i], b[i], c[i]);
    }
}
