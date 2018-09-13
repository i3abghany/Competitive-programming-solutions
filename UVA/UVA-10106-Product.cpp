#include <bits/stdc++.h>

typedef std::vector<long long int> vll;

using namespace std;

int main() {
    string x, y;
    while(cin >> x) {
        if(x == "0" || y == "0") {
            cout << 0 << endl;
            continue;
        }
        cin >> y;
        reverse(x.begin(), x.end());
        reverse(y.begin(), y.end());
        int a[600] = {0};
        for(int i = 0; i < x.length(); i++) {
            for(int j = 0; j < y.length(); j++) {
                a[i + j] += (x[i] - '0') * (y[j] - '0');
            }
        }
        for(int i = 0; i < 599; i++) {
            a[i+1] += a[i] / 10;
            a[i] %= 10;
        }
        int i = 599;
        while(i > 0 && a[i] == 0) i--;
        for(; i >= 0; i--) cout << a[i];
        cout << endl;
    }
    return 0;
}
