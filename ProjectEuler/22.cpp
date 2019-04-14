#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<string> names {
    // unnecessary stuff.       
};

int score(const std::string& s) {
    int res = 0;
    for(auto ch : s)
        res += (int)ch - 64;
    return res;
}

int main() {
    long long res = 0;
    sort(begin(names), end(names));
    for(int i = 0; i < names.size(); i++) {
        int scr = score(names[i]);
        scr *= (i + 1);
        res += scr;
    }
    cout << res;
}

