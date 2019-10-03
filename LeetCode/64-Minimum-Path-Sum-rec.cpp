
class Solution {
public:
    constexpr static std::size_t maxN = 1000;
    int dp[maxN][maxN];
    int n, m;

    int minPathSum(std::vector<std::vector<int>>& grid) {
        n = grid.size();
        m = grid[0].size();
        memset(dp, -1, sizeof dp);
        return sol(grid, 0, 0);
    }

    bool valid(int r, int c) {
        return r >= 0 && r < n && c >= 0 && c < m;
    }

    int sol(std::vector<std::vector<int>>& arr_grid, int r, int c) {
        if(!valid(r, c)) return std::numeric_limits<int>::max();
        if(dp[r][c] != -1) return dp[r][c];

        int min = std::min(sol(arr_grid, r + 1, c), sol(arr_grid, r, c + 1));
        int ans = arr_grid[r][c] + (min == std::numeric_limits<int>::max() ? 0 : min);
        dp[r][c] = ans;
        return ans;
    }

};
