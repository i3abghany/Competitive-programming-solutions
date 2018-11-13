#include <bits/stdc++.h>

#define all(x) x.begin(),x.end()

using namespace std;

int main() {
    int n;
    cin >> n;
    while(n--) {
        int tt; cin >> tt;
        vector<string> p;
        string s;
        while(tt--) {
            cin >> s;
            p.emplace_back(s);
        }
        while(cin >> s && s != "END") {
            string tmp = s;
            vector<string> anag;
            sort(all(tmp));
            for(auto x : p) {
                string tmp2 = x;
                sort(all(tmp2));
                if(tmp == tmp2)
                    anag.emplace_back(x);
            }
            cout << "Anagrams for: " << s << endl;
            for(int i = 0; i < anag.size(); i++) {
                cout << "  " << i + 1 << ") ";
                cout << anag[i] << endl;
            }
            if(anag.size() == 0)
                cout << "No anagrams for: " << s << endl;
        }
        if(n) cout << endl;
    }
}
