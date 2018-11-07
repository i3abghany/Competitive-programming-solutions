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
    int tc; cin >> tc;
    cin.ignore();
    while(tc--) {
        getline(cin, s);
        map<char, int> mp;
        for(int i = 0; i < s.L; i++)
            if(s[i] != ' ')
                mp[s[i]]++;
        if(mp['M'] == mp['F'] && s.L > 3)
            cout << "LOOP" << endl;
        else cout << "NO LOOP" << endl;
    }
}