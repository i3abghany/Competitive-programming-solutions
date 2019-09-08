#include <bits/stdc++.h>

int n, p;
std::vector<int> v;

bool sol(int idx, int curr) {
    if(curr == n) return true;
    if(idx == p) return curr == n;

    return sol(idx + 1, curr + v[idx]) || sol(idx + 1, curr);
}

int main() {
    int tc; std::cin >> tc;
    while(tc--) {
        std::cin >> n >> p;
        v.clear(); v.resize(p);
        for(int &el : v) std::cin >> el;
        std::cout << (sol(0, 0) ? "YES" : "NO") << '\n';
    }
    return 0;
}
