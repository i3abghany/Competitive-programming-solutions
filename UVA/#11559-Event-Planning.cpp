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
//#ifdef ONLINE_JUDGE
//    ios_base::sync_with_stdio(0);
//    cin.tie(0);
//#endif

 //   freopen("in.txt", "r", stdin);
 //   freopen("out.txt", "w", stdout);
    int N, H, B, W;
    while(cin >> N >> B >> H >> W && !cin.eof()) {
        int p, res = 12345678, kk;
        for(int i = 0; i < H; i++) {
            cin >> p;
            for(int j = 0; j < W; j++) {
                cin >> kk;
                if(kk >= N)
                    res = min(res, N * p);
            }
        }
        if(res == 12345678 || B < res)
            cout << "stay home" << endl;
        else
            cout << res << endl;
    }
}
