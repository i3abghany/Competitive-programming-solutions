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
const double eps =  0.0000001;

int main() {
#ifdef ONLINE_JUDGE
    ios_base::sync_with_stdio(0);
    cin.tie(0);
#endif
//    freopen("C:\\Users\\Mohamed\\CLionProjects\\Codeforces\\in.txt", "r", stdin);
//    freopen("C:\\Users\\Mohamed\\CLionProjects\\Codeforces\\out.txt", "w", stdout);
    int n, m, c, tc = 0;

    cin >> n >> m >> c;
    while(true) {
        bool flag = 0;
        vector<pair<int, int>> p(n); // state and capacitance.
        for(int i = 0; i < n; i++) {
            p[i].first = 0;
            cin >> p[i].second;
        }
        int mxCap = 0, curr = 0, tmp;
        for(int i = 0; i < m; i++) {
            cin >> tmp;
            tmp--;
            if(p[tmp].first == 1) {
                curr -= p[tmp].second;
                p[tmp].first = 0;
            } else {
                curr += p[tmp].second;
                p[tmp].first = 1;
            }
            mxCap = max(mxCap, curr);
        }
        if(mxCap > c) {
            cout << "Sequence " << ++tc << endl;
            cout << "Fuse was blown." << endl;
        } else {
            cout << "Sequence " << ++tc << endl;
            cout << "Fuse was not blown." << endl;
            cout << "Maximal power consumption was " << mxCap << " amperes." << endl;
        }
        if(cin >> n >> m >> c && (n || m || c)) cout << endl;
        else break;
    }
    cout << endl;
}