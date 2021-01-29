// 673 Number of Longest Increasing Subsequence
// link :: https://leetcode.com/problems/number-of-longest-increasing-subsequence/

class Solution {
public:
    int findNumberOfLIS(vector<int>& nums) {
        
        int n = nums.size();
        int dp[nums.size()+1], cnt[n];
        for(int i=0;i<n;i++)
        {
            dp[i] = 1;
            for(int j=0;j<i;j++)
            {
                if(nums[i] > nums[j])
                    dp[i] = max(dp[i], dp[j]+1);
            }
        }
        
        for(int i=0;i<n;i++)
        {
            if(dp[i] == 1)
                cnt[i] = 1;
            else
            {
                cnt[i] = 0;
                for(int j=0;j<i;j++){
                    if(dp[i] == dp[j]+1 && nums[i] > nums[j]){
                        cnt[i] += cnt[j];
                    }
                }  
            }
        }
        
        int mx = 0, sum = 0;
        for(int i=0;i<n;i++){
            mx = max(mx, dp[i]);
        }
        
        for(int i=0;i<n;i++){
            if(mx == dp[i]){
                sum += cnt[i];
            }
        }
        return sum;
    }
};
