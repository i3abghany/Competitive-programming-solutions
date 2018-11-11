#include <bits/stdc++.h>

typedef long long ll;

using namespace std;

inline void removeNonAlphaNumeric(string& s) {
    s.erase(remove_if(s.begin(), s.end(), not1(ptr_fun((int(*)(int))isalnum ))), s.end());
}

bool is_palindrome(string s) {
    for(int i = 0; i < s.length() / 2; i++) {
        if(s[i] != s[s.length() - i - 1])
            return 0;
    }
    return 1;
}

int main() {
#ifdef ONLINE_JUDGE
    ios_base::sync_with_stdio(0);
    cin.tie(nullptr);
#endif
    int n, c = 1; string s;
    cin >> n; cin.ignore();
    while(n--) {
        getline(cin, s);
        removeNonAlphaNumeric(s);
        int t = sqrt(s.length());
        cout << "Case #" << c++ << ":\n";
        if(t * t != s.length()) {
            cout << "No magic :(\n";
            continue;
        }
        if(!is_palindrome(s)) {
            cout << "No magic :(\n";
            continue;
        }
        cout << t << endl;
    }
}

// Gentlemen, it's a very sad thing to be nothing.
