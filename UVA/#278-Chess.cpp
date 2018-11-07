#include <bits/stdc++.h>
#include <random>
#define all(x) (x).begin(), x.end()
#define eb emplace_back
#define pb push_back
#define L length()

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef vector<pair<int, int> > vpii;

const int maxN = (int)1e5 + 2;
const double eps =  0.0000001;

int main() {
#ifdef ONLINE_JUDGE
    ios_base::sync_with_stdio(0);
    cin.tie(0);
#endif
    char k;
    int n, m, tc;
    cin >> tc;
    while(tc--) {
        cin >> k >> n >> m;
        int res;
        switch (k){
            case 'r':
                res = min(n, m);
                break;
            case 'K':
                res = (int)ceil(1.0 * ceil(1.0 * n / 2.0) * 1.0 * ceil(1.0 * m / 2.0));
                break;
            case 'k':
                res = (n * m / 2);
                break;
            case 'Q':
                res = min(n, m);
                break;
            default:
                break;
        }
        if(k == 'k' && (n * m)&1)
            ++res;
        cout << res << endl;
    }
}