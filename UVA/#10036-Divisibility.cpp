#include <iostream>
#include <vector>
#include <cstring>

std::vector<int> ser;
int k;

// max mod is arbitrarily chosen is there are no boundaries specified by the problem.
constexpr int maxn = 101, max_mod = 20000;
int dp[maxn][max_mod];

int fix(int a, int b) {
    return ((a % k + b % k) + k) % k;
}

bool sol(int idx, int curr_mod) {
    if(dp[idx][curr_mod] != -1) return dp[idx][curr_mod];
    if(idx == ser.size()) return curr_mod == 0;

    return dp[idx][curr_mod] = sol(idx + 1, fix(curr_mod, ser[idx])) || sol(idx + 1, fix(curr_mod, - ser[idx]));
}

int main() {
    int TC;
    std::cin >> TC;
    while(TC--) {
        memset(dp, -1, sizeof dp);
        int N;
        std::cin >> N >> k;
        ser.resize(N);
        for (int &a : ser) std::cin >> a;
        std::cout << (sol(1, ser[0]) ? "Divisible" : "Not divisible") << '\n';
    }
    return 0;
}
