#include <bits/stdc++.h>

#define all(x) (x).begin(), x.end()
#define eb emplace_back
#define pb push_back

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef vector<pair<int, int>> vpii;
const int maxN = (int)1e5;


int main() {
#ifdef ONLINE_JUDGE
    ios_base::sync_with_stdio(0);
    cin.tie(0);
#endif

//    freopen("in.txt", "r", stdin);
//    freopen("out.txt", "w", stdout);
    int t, c = 0;
    cin >> t;
    while(t--) {
        int n, h = 0, l = 0; vi p;
        cin >> n;
        for(int i = 0, tmp; i < n; i++) {
            cin >> tmp;
            p.emplace_back(tmp);
        }
        int res = p[0];
        for(int x : p) {
            if(res - x > 0)
                h++;
            else if(res - x < 0)
                l++;
            res = x;
        }
        swap(h, l);
        cout << "Case " << ++c  << ": " << h << " " << l << endl;
        h = l = 0;
    }
}
