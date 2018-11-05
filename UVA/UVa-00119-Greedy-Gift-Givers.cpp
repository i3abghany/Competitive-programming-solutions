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

template<class T, class C> class Map {
public:
    vector<pair<T, C>> p;
    void insert(pair<T, C> k) {
        p.eb(k);
    }
    
    C& operator[](T xx) {
        for(int i = 0; i < p.size(); i++) {
            if(p[i].first == xx)
                return p[i].second;
        }
        p.pb(make_pair(xx, 0));
        return p[p.size() - 1].second;
    }
};

int main() {
#ifdef ONLINE_JUDGE
    ios_base::sync_with_stdio(0);
    cin.tie(0);
#endif
    int tc; cin >> tc;
    while(1) {
        Map<string, int> mp;
        string s; int tmp;
        for(int i = 0; i < tc; i++) {
            cin >> s;
            mp[s] = 0;
        }
        int n;
        for(int i = 0; i < tc; i++) {
            cin >> s >> tmp >> n;
            if (n) mp[s] -= n * (tmp / n);
            for(int x = 0; x < n; x++) {
                cin >> s;
                mp[s] += tmp / n;
            }
        }
        for(auto xt : mp.p)
            cout << xt.first << " " << xt.second << endl;
        if(cin >> tc) cout << endl;
        else break;
    }
}
