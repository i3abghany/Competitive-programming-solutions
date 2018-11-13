#include <bits/stdc++.h>

#define all(x) x.begin(),x.end()

using namespace std;

int main() {

    string s;
    vector<string> vs;
    while(cin >> s && (s != "#")) {
        vs.push_back(s);
    }
    vector<pair<string, string> > mppp;
    set<string> SET;
    for(string ss : vs) {
        string tmp = ss;
        for(int i = 0; i < tmp.length(); i++)
            tmp[i] = (char)tolower(tmp[i]);
        sort(all(tmp)); bool f = 0, found = 0;
        for(const string& tt : vs) {
            if(tt == ss && found == 0) {
                found = 1;
                continue;
            }
            string tmp2 = tt;
            for(int i = 0; i < tmp2.length(); i++)
                tmp2[i] = (char)tolower(tmp2[i]);
            sort(all(tmp2));
            if(tmp == tmp2) {
                f = 1;
                break;
            }
        }
        if(!f) SET.insert(ss);
    }
    for(auto x : SET) {
        cout << x << endl;
    }
}
