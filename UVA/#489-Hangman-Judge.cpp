#include <bits/stdc++.h>

using namespace std;

template <typename T>
inline void removeDups(vector<T>& a) {
    auto end_unique = std::end(a);
    for(auto iter = std::begin(a); iter != end_unique; ++iter) {
        end_unique = std::remove(iter+1, end_unique, *iter) ;
    }
    a.erase(end_unique, std::end(a));
}
template <typename T>
inline int isThere(vector<T>& a, T b) {
    for(T x : a) {
        if(x == b)
            return 1;
    }
    return -1;
}

int main() {
#ifdef ONLINE_JUDGE
    ios_base::sync_with_stdio(0);
    cin.tie(nullptr);
#endif
    int n;
    while(cin >> n && (n != -1)) {
        string right, guess;
        cin >> right >> guess;
        vector<char> dr, dg;
        for(auto x : right)
            dr.push_back(x);
        for(auto x : guess)
            dg.push_back(x);

        removeDups(dr);
        removeDups(dg);

        int good = 0, bad = 0;
        for(auto x : dg) {
            if(good == dr.size() || bad >= 7) break;
            if(isThere(dr, x) != -1) {
                good++;
            }
            else bad++;
        }
//        cout << endl;
//        cout << good << " " << dr.size() << endl;
//        for(auto x : dr) cout << x << " ";
//        cout << endl;
//        for(auto x : dg) cout << x << " ";
//        cout << endl;
        cout << "Round " << n << endl;
        if(good == dr.size()) {
            cout << "You win." << endl;
            continue;
        } else if(bad >= 7) {
            cout << "You lose." << endl;
            continue;
        } else if(good < dr.size() && bad < 7) {
            cout << "You chickened out." << endl;
            continue;
        }
    }

}