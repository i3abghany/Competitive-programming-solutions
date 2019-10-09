#include <iostream>
#include <vector>

class MatchNumbersEasy {
private:
    std::vector<std::string> dp;
    std::vector<int> matches_vector;
    bool first = true;
public:
    std::string maxNumber(const std::vector<int>& matches, const int n) {
        matches_vector = matches;
        dp.assign(n + 1, std::string("-"));
        const std::string answer = maxNumberUtil(n);
        return answer.empty() ? "0" : answer;
    }

    std::string maxNumberUtil(int curr_n) {
        if(curr_n == 0) return "";

        if(dp[curr_n] != "-") {
            return dp[curr_n];
        }

        std::string max_glob, max_now;

        for(int i = 0; i < matches_vector.size(); i++) {
            if(first && !i) {
                first = false;
                continue;
            }
            if(matches_vector[i] > curr_n) continue;
            max_now = std::string(1, char(48 + i)) + maxNumberUtil(curr_n - matches_vector[i]);
            if(max_glob.size() < max_now.size() || (max_glob.size() == max_now.size() && max_now > max_glob)) {
                max_glob = max_now;
            }
        }
        return dp[curr_n] = max_glob;
    }
};
