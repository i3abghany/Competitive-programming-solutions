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

    string s;
    int tc = 0, n;
    while(cin >> s >> n) {
        cout << "Case " << ++tc << ":" <<endl;
        while(n--) {
            int i, j; bool flag = false;
            cin >> i >> j;
            if(j < i) swap(i, j);
            char tmp = s[i];
            for(int k = i; k <= j; ++k) {
                if (s[k] != s[i]) {
                    flag = true;
                    break;
                }
            }
            if(flag) cout << "No\n";
            else cout << "Yes\n";
        }
    }

}