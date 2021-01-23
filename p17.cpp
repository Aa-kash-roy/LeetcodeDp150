// link:: https://leetcode.com/problems/number-of-dice-rolls-with-target-sum/
class Solution {
public:
    vector<int> vec;
    
    int dp[35][1005], mod = (int)1e9+7;
    int go(int idx, int target, int d)
    {
        if(target < 0)
            return 0;
        if(idx == d)
        {
            if(target == 0)
                return 1;
            return 0;
        }
        if(dp[idx][target] != -1)
            return dp[idx][target]%mod;
        
        int ans = 0;
        for(auto x: vec)
        {
            ans += go(idx+1, target - x, d);
            ans %= mod;
        }
        return dp[idx][target] = ans%mod;
    }
    
    int numRollsToTarget(int d, int f, int target) {
        
        for(int i=1;i<=f;i++)
            vec.push_back(i);
        memset(dp, -1, sizeof(dp));
        return go(0, target, d)%mod;
    }
};
