// link :: https://leetcode.com/problems/perfect-squares/
class Solution {
public:
    
    int dp[10005];
    int go(int val)
    {
        int k = sqrt(val);
        if(k*k == val)
            return 1;
        if(dp[val] != -1)
            return dp[val];
        int ans = INT_MAX;
        for(int i=1;i<=k;i++)
        {
            ans = min(ans, (1 + go(val - i*i)));
        }
        return dp[val] = ans;
    }
    
    int numSquares(int n) {
        memset(dp, -1, sizeof(dp));
        return go(n);
    }
};
