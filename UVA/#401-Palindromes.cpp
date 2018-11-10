#include <bits/stdc++.h>

typedef long long ll;

using namespace std;

map<char, char> mp;

bool is_palindrome(string s) {
    for(int i = 0; i < s.length() / 2; i++) {
        if(s[i] != s[s.length() - i - 1])
            return 0;
    }
    return 1;
}

bool is_mirrored(string s) {
    for(int i = 0; i <= s.length() / 2; i++) {
        if(s[s.length() - 1 - i] != mp[s[i]])
            return 0;
    }
    return 1;
}

void init() {
    string original = "ABCDEFGHIJKLMNOPQRSTUVWXYZ123456789";
    string reverse =  "A   3  HIL JM O   2TUVWXY51SE Z  8 ";
    for (int i = 0; i < 26 + 9; ++i)
        mp[original[i]] = reverse[i];
}

int main() {
#ifdef ONLINE_JUDGE
    ios_base::sync_with_stdio(0);
    cin.tie(nullptr);
#endif
    string s;
    init();
    cin >> s;
    while(1) {
        bool pal = is_palindrome(s), mir = is_mirrored(s);
        if(pal && mir) {
            cout << s << " -- is a mirrored palindrome." << endl;
        } else if(pal && !mir) {
            cout << s << " -- is a regular palindrome." << endl;
        } else if(!pal && !mir) {
            cout << s << " -- is not a palindrome." << endl;
        } else if(!pal && mir) {
            cout << s << " -- is a mirrored string." << endl;
        }
        if(cin >> s) cout << endl;
        else {
            cout << endl;
            break;
        }
    }
}
