#include <iostream>
#include <vector>

class NumberofFiboCalls {
private:
    std::vector<std::pair<int, int>> dp;
public:
    std::vector<int> fiboCallsMade(const int n) {
        dp.assign(n + 1, {-1, -1});
        const auto ans = fiboCallsMadeUtil(n);
        return {ans.first, ans.second};
    }

    std::pair<int, int> fiboCallsMadeUtil(const int n) {
        if (dp[n].first != -1 && dp[n].second != -1) return dp[n];
        if (n == 0) {
            return {1, 0};
        }
        if (n == 1) {
            return {0, 1};
        }
        dp[n] = {0, 0};
        auto p1 = fiboCallsMadeUtil(n - 1), p2 = fiboCallsMadeUtil(n - 2);
        return dp[n] = {p1.first + p2.first, p1.second + p2.second};
    }
};
