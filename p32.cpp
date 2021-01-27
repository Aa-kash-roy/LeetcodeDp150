
// link :: https://leetcode.com/problems/integer-break/
class Solution {
    
    int dp[105];
    int go(int n)
    {
        if(n<=3)
            return n;
        if(dp[n] != -1)
            return dp[n];
        
        int ans = 0;
        for(int i=2;i<=n/2;i++)
        {
            ans = max(ans, go(i)*go(n-i));
        }
        return dp[n] = ans;
    }
public:
    int integerBreak(int n) {
        
        if(n==2 || n==3)
            return n-1;
        memset(dp,-1,sizeof(dp));
        return go(n);
    }
};
