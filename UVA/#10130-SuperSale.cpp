#include <iostream>
#include <vector>
#include <algorithm>

                 // value, weight
std::vector<std::pair<int, int>> items;
std::vector<int> people;

         //    dp[idx][rem]
std::vector<std::vector<int>> dp;

int main() {
    int T;
    std::cin >> T;
    while(T--) {
        int N;
        std::cin >> N;
        items.clear();
        items.resize(N);
        for (auto &item : items) {
            std::cin >> item.first >> item.second;
        }
        int G;
        std::cin >> G;
        people.clear();
        people.resize(G);

        for (auto &person : people) {
            std::cin >> person;
        }

        const int MW = *std::max_element(std::begin(people), std::end(people));
        dp.clear();
        dp.assign(N + 1, std::vector<int>(MW + 1, 0));
        for(int i = 1; i <= N; i++) {
            for(int w = 1; w <= MW; w++) {
                if(items[i - 1].second <= w) {
                    dp[i][w] = std::max(dp[i - 1][w - items[i - 1].second] + items[i - 1].first, dp[i - 1][w]);
                } else {
                    dp[i][w] = dp[i - 1][w];
                }
            }
        }

        int ans = 0;
        for(auto &person : people) {
            ans += dp[N][person];
        }

        std::cout << ans << std::endl;
    }
}
