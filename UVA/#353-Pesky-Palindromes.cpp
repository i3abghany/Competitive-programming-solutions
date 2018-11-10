#include <bits/stdc++.h>

typedef long long ll;

using namespace std;

int is_palindrome(string s) {
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
    while(cin >> s) {
        set<string> st;
        for(int i = 0; i < s.length(); i++) {
            for(int j = i; j < s.length(); j++) {
                string tmp = s.substr(i, j - i + 1);
                if(is_palindrome(tmp))
                    st.insert(tmp);
            }
        }
        cout << "The string \'" << s << "\' contains " << st.size() << " palindromes." << endl;
    }
}
