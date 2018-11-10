#include <bits/stdc++.h>

typedef long long ll;

using namespace std;

template<typename T>
inline void removeNonAlphaNumeric(string& s) {
    s.erase(remove_if(s.begin(), s.end(), not1(ptr_fun((int(*)(int))isalnum))), s.end());
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
    string s;
    while(getline(cin, s) && (s != "DONE")) {
        for(int i = 0; i < s.length(); i++) {
            s[i] = tolower(s[i]);
        }
        removeNonAlphaNumeric(s);
        if(is_palindrome(s))
            cout << "You won't be eaten!" << endl;
        else cout << "Uh oh.." << endl;
    }

}
