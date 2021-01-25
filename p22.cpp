// link :: https://leetcode.com/problems/combination-sum-iv/
class Solution {
public:
    
    int go(vector<int> &nums, int sum, vector<int> &dp)
    {
        if(sum < 0)
            return 0;
        
        if(sum == 0)
            return 1;
        
        if(dp[sum] != -1)
            return dp[sum];
        int ans = 0;
        for(auto x: nums)
        {
            if(x <= sum)
                ans += go(nums, sum-x, dp);
        }
        return dp[sum] = ans;
    }
    
    int combinationSum4(vector<int>& nums, int target) {
        vector<int> dp(target+1, -1);
        return go(nums, target, dp);
    }
};
