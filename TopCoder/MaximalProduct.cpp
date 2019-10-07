#include <iostream>
#include <vector>

std::vector<std::vector<long long>> dp;

class MaximalProduct {
public:

    long long maximalProduct(int s, int k) {
        dp.assign(k + 1, std::vector<long long int>(s + 1, -1));
        return maximalProductUtil(0, k, s);
    }

private:
    long long maximalProductUtil(int idx, int k, int rem) {
        if (idx == k && rem == 0) return 1;
        if (idx == k) return 0;

        long long int &ret = dp[idx][rem];

        if (ret != -1) return ret;

        ret = 0;

        for (int i = 1; i <= rem; i++) {
            ret = std::max(ret, i * maximalProductUtil(idx + 1, k, rem - i));
        }

        return ret;
    }
};

int main() {
    MaximalProduct s;
    std::cout << s.maximalProduct(10, 3);
}
