// link :: https://leetcode.com/problems/delete-and-earn/
class Solution {
public:
    int deleteAndEarn(vector<int>& nums) {
        // dp[i] denotes maximum point one can get upto ith 
        //  number. 
        int freq[1005] = {0}, dp[1005];
        for(auto x: nums)
            freq[x]++;
        
        int ans1 = 0, ans2 = 0;
        dp[0] = 0, dp[1] = freq[1];
        for(int i=2;i<=1000;i++)
        {
            dp[i] = max(i*freq[i]+dp[i-2], dp[i-1]);
        }
        return dp[1000];
    }
};
