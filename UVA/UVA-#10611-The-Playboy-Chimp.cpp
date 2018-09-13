#include <bits/stdc++.h>

using namespace std;

int main() {
    int n;
    cin >> n;
    int a[n];
    for(int i = 0; i < n; i++) scanf("%d", &a[i]);
    int Q;
    cin >> Q;
    int b[Q];

    for (int j = 0; j < Q; ++j) scanf("%d", &b[j]);

    for (int i = 0; i < Q; ++i) {
        int q = b[i];
        int highest = INT_MIN, lowest = INT_MAX;
        for (int j = 0; j < n; ++j) {
            if(a[j] < q)
                highest = max(highest, a[j]);
            if(a[j] > q)
                lowest = min(lowest, a[j]);
        }
        if(highest != INT_MIN) cout << highest << " ";
        else cout << "X ";
        if(lowest != INT_MAX) cout << lowest;
        else cout << "X";
        cout << endl;
        highest = INT_MIN;
    }
}
