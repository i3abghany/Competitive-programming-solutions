#include <bits/stdc++.h>

using namespace std;

int main() {
    int n, Q, q, c = 1;
    int a[n];    
    while(cin >> n >> Q && (n || Q)) {
        for (int i = 0; i < n; ++i) scanf("%d", &a[i]);
        sort(a, a+n);
        cout << "CASE# " << c++ << ":\n";
        while(Q--) {
            cin >> q;
            auto x = lower_bound(a, a+n, q);
            if(x != a+n && *x == q) {
                cout << q << " found at " << (x - a + 1) << endl;
            } else {
                cout << q << " not found" << endl;
            }
        }
    }
}
