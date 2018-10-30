#include <bits/stdc++.h>

#define all(x) (x).begin(), (x).end()
#define eb emplace_back
#define pb push_back

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef vector<pair<int, int>> vpii;

const int maxN = (int)1e5;
const int inf = (int)(1 << 30);
const double pi = 2 * acos(0);

int solve(int n) {
    if(n < 10)
        return n;
    string s = to_string(n);
    int tmp = 0;
    for(int i = 0; i < s.length(); i++)
        tmp += (s[i] - '0');
    return solve(tmp);
}

int main() {
#ifdef ONLINE_JUDGE
    ios_base::sync_with_stdio(0);
    cin.tie(0);
#endif

//    freopen("in.txt", "r", stdin);
//    freopen("out.txt", "w", stdout);
    int n;
    while(cin >> n && n) {
        int t = solve(n);
        cout << t << endl;
    }
}
