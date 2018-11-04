#include <bits/stdc++.h>

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

int main() {
#ifdef ONLINE_JUDGE
    ios_base::sync_with_stdio(0);
    cin.tie(0);
#endif

    int T, c = 0; cin >> T;
    while(T--) {
        vector<pair<string, int>> p;
        string tmp; int q, mx = 0;
        for(int i = 0; i < 10; i++) {
            cin>> tmp >> q;
            p.eb(make_pair(tmp, q));
            mx = max(mx, q);
        }
        cout << "Case " << "#" << ++c << ":" << endl;
        for(auto x : p) {
            if(x.second == mx)
                cout << x.first << endl;
        }
    }
}
