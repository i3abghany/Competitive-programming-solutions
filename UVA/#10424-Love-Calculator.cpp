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

int xD(int n) {
    if(n < 10)
        return n;
    string s = to_string(n);
    int tmp = 0;
    for(int i = 0; i < s.length(); i++)
        tmp += (s[i] - '0');
    return xD(tmp);
}
int main() {
#ifdef ONLINE_JUDGE
    ios_base::sync_with_stdio(0);
    cin.tie(0);
#endif
    string s, n;
    while(cin >> s >> n) {
        int r1 = 0, r2 = 0;
        for(int i = 0; i < s.L; i++) {
            if(isalpha(s[i]))
                r1 += tolower(s[i]) - 'a' + 1;
        }
        for(int i = 0; i < n.L; i++) {
            if(isalpha(n[i]))
                r2 += tolower(n[i]) - 'a' + 1;
        }
        r1 = xD(r1), r2 = xD(r2);
        if(r1 > r2) swap(r1, r2);
        cout << fixed << setprecision(2) << (100.0 * r1 / (r2 * 1.0)) << " %" << endl;
    }
}