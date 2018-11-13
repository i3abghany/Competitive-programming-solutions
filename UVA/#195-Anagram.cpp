#include <bits/stdc++.h>

#define all(x) x.begin(),x.end()

using namespace std;

bool cmp(char x, char y) {
    if(tolower(x) == tolower(y))
        return x < y;
    return (tolower(x) < tolower(y));
}

int main() {
    int n; cin >> n;
    while(n--) {
        cin.ignore();
        string s;
        cin >> s;
        sort(all(s), cmp);
        do {
            cout << s << endl;
        } while(next_permutation(all(s), cmp));
    }
}

