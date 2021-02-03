// link :: https://leetcode.com/problems/number-of-ways-to-stay-in-the-same-place-after-some-steps/
class Solution {
public:
    
    int dp[505][255], mod = 1e9+7;
    long long go(int st, int len, int pos)
    {
        if(st==0)
        {
            if(pos == 0)
                return 1;
            return 0;
        }
        if(pos<0||pos>=len||pos>st)					
            return 0;
        
        if(dp[st][pos] != -1)
            return dp[st][pos]%mod;
        
        return dp[st][pos] = (go(st - 1, len, pos+1)%mod + go(st-1, len, pos-1)%mod + go(st-1, len, pos)%mod)%mod;
    }
    
    int numWays(int steps, int arrLen) {
        memset(dp, -1, sizeof(dp));
        return go(steps, arrLen, 0);
    }
};
