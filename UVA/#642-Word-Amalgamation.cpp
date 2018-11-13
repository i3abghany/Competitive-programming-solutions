#include <bits/stdc++.h>

#define all(x) x.begin(),x.end()

using namespace std;

int main() {
    string s;
    unordered_set<string> st;
    while(cin >> s && s != "XXXXXX") {
        st.insert(s);
    }
    while(cin >> s && s != "XXXXXX") {
        set<string> anag;
        string tmp = s;
        sort(all(tmp));
        do {
            if(st.find(tmp) != st.end())
                anag.insert(tmp);
        } while(next_permutation(all(tmp)));
        for(auto x : anag)
            cout << x << endl;
        if(anag.size() == 0)
            cout << "NOT A VALID WORD" << endl;
        cout << "******" << endl;
    }
}

