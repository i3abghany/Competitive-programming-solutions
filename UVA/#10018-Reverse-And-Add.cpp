#include <bits/stdc++.h>

typedef long long ll;

using namespace std;

bool is_palindrome(string s) {
    for(int i = 0; i < s.length() / 2; i++) {
        if(s[i] != s[s.length() - i - 1])
            return 0;
    }
    return 1;
}

inline ll rev(int x) {
    string t = to_string(x);
    reverse(t.begin(), t.end());
    ll tt = stoll(t);
    return tt;
}

int main() {
#ifdef ONLINE_JUDGE
    ios_base::sync_with_stdio(0);
    cin.tie(nullptr);
#endif
    int n;
    cin >> n;
    while(n--) {
        ll x, cnt = 1; cin >> x;
        x += rev(x);
        while(!is_palindrome(to_string(x)))
            x += rev(x), cnt++;
        cout << cnt << " " << x << endl;
    }
}
