class Solution {
public:
    int dp[10000];
    
    int sol(int curr, int N) {
        if(curr == N) return 1;
        if(curr >  N) return 0;
        
        if(dp[curr] != -1) return dp[curr];
        
        int ans = 0;
        
        if(dp[curr + 1] != -1) ans += dp[curr + 1];
        else ans += (dp[curr + 1] = sol(curr + 1, N));
        
        if(dp[curr + 2] != -1) ans += dp[curr + 2];
        else ans += (dp[curr + 2] = sol(curr + 2, N));
        
        return ans;
    }
    
    int climbStairs(int n) {
        std::fill(std::begin(dp), std::end(dp), -1);
        
        return sol(0, n);
    }
};
