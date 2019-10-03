class Solution {
public:
    constexpr static std::size_t maxN = 1000;
    int dp[maxN][maxN];
    int n, m;

    int minPathSum(std::vector<std::vector<int>>& grid) {
        n = grid.size();
        m = grid[0].size();
        dp[n - 1][m - 1] = grid[n - 1][m - 1];

        for(int i = n - 2; i >= 0; i--) {
            dp[i][m - 1] = dp[i + 1][m - 1] + grid[i][m - 1];
        }

        for(int i = m - 2; i >= 0; i--) {
            dp[n - 1][i] = dp[n - 1][i + 1] + grid[n - 1][i];
        }

        for(int i = n - 2; i >= 0; i--) {
            for(int j = m - 2; j >= 0; j--) {
                dp[i][j] = std::min(dp[i + 1][j], dp[i][j + 1]) + grid[i][j];
            }
        }

        return dp[0][0];
    }


};
