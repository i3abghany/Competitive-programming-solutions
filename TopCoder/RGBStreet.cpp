#include <iostream>
#include <vector>
#include <cstring>
#include <sstream>
#include <limits>

constexpr std::size_t max = 20;

std::vector<int> r(max), g(max), b(max);
std::vector<std::vector<int>> dp(max, std::vector<int>(3, -1));

class RGBStreet {
public:

    enum class color : std::uint8_t {
        RED = 0,
        GREEN = 1,
        BLUE = 2,
        ANOTHER_FANCY_COLOR = 3
    };

    int estimateCost(const std::vector<std::string> &v) {
        int i = 0;
        for (auto &s : v) {
            std::istringstream iss(s);
            iss >> r[i] >> g[i] >> b[i];
            ++i;
        }
        return estimateCostUtil(0, v.size(), color::ANOTHER_FANCY_COLOR);
    }

private:
    int estimateCostUtil(const std::size_t idx, const std::size_t num_of_houses, const color last_color) {
        if (idx == num_of_houses) return 0;

        if(last_color == color::ANOTHER_FANCY_COLOR) {}
        else if(dp[idx][static_cast<int>(last_color)] != -1) return dp[idx][static_cast<int>(last_color)];

        int& ret = dp[idx][static_cast<int>(last_color)];

        ret = std::numeric_limits<int>::max();
        if (last_color != color::RED) {
            ret = std::min(ret, r[idx] + estimateCostUtil(idx + 1, num_of_houses, color::RED));
        }

        if (last_color != color::GREEN) {
            ret = std::min(ret, g[idx] + estimateCostUtil(idx + 1, num_of_houses, color::GREEN));
        }

        if (last_color != color::BLUE) {
            ret = std::min(ret, b[idx] + estimateCostUtil(idx + 1, num_of_houses, color::BLUE));
        }
        return ret;
    }
};
