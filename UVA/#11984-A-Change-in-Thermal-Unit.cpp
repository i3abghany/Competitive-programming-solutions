#include <bits/stdc++.h>

#define all(x) x.begin(),x.end()

using namespace std;

int main() {
    int n;
    double c, f;
    cin >> n;
    for(int i = 1; i <= n; i++) {
        cin >> c >> f;
        c = ((9.0 / 5.0) * c) + 32;
        c += f;
        c = (c - 32) * (5.0 / 9.0);
        cout << fixed << setprecision(2) << "Case " << i << ": " << c << endl;
    }
}
