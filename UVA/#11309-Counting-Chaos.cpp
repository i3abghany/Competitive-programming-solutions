#include <bits/stdc++.h>

typedef long long ll;

using namespace std;

inline void removeNonAlphaNumeric(string& s) {
    s.erase(std::remove_if(s.begin(), s.end(), std::not1(std::ptr_fun((int(*)(int))std::isalnum ))), s.end());
}

inline void removeLeadingZeros(string& s) {
    s.erase(0, min(s.find_first_not_of('0'), s.size()-1));
}

bool is_palindrome(string s) {
    removeLeadingZeros(s);
    for(int i = 0; i <= s.length() / 2; i++) {
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
    int n; cin >> n;
    while(n--) {
        string s;
        cin >> s;
        removeNonAlphaNumeric(s);
        string tmph = ""; tmph += s[0], tmph += s[1];
        string tmpm = ""; tmpm += s[2], tmpm += s[3];
        int hrs = stoi(tmph), mns = stoi(tmpm);
        mns++;
        if(mns == 60) hrs = (hrs + 1) % 24;
        mns %= 60;
        tmph = to_string(hrs), tmpm = to_string(mns);
        s = "";
        if(tmph.length() == 1) {
            s += '0'; s+= tmph;
        } else s += tmph;
        if(tmpm.length() == 1) {
            s += '0'; s+= tmpm;
        } else s += tmpm;
        while(!is_palindrome(s)) {
            s = "";
            mns++;
            if(mns == 60) hrs = (hrs + 1) % 24;
            mns %= 60;
            tmph = to_string(hrs), tmpm = to_string(mns);
            if(tmph.length() == 1) {
                s += '0'; s+= tmph;
            } else s += tmph;
            if(tmpm.length() == 1) {
                s += '0'; s+= tmpm;
            } else s += tmpm;
        }
        cout << setw(2) << setfill('0') << tmph;
        cout << ":";
        cout << setw(2) << setfill('0') << tmpm << endl;
    }
}
