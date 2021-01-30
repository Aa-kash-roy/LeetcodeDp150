// link :: https://leetcode.com/problems/predict-the-winner/
class Solution {
public:
    
    int dp[25][25];
    int go(vector<int>& nums, int l, int r){
        
        // cout<<"Im here for :: "<<l<<" "<<r<<endl;
        if(l > r)
            return 0;
        if(l==r)
            return nums[l];
        // if(l+1 == r)
        //     return max(nums[l], nums[r]);
        if(dp[l][r] != -1)
            return dp[l][r];
        int op1 = nums[l] + min(go(nums, l+2, r), go(nums, l+1, r-1));
        int op2 = nums[r] + min(go(nums, l+1, r-1), go(nums, l, r-2));
        
        return dp[l][r] = max(op1, op2);
    }
    
    bool PredictTheWinner(vector<int>& nums) {
        
        memset(dp, -1, sizeof(dp));
        int n = nums.size();
        if(n == 1)
            return 1;
        int sum = 0;
        for(auto x: nums)
            sum += x;
        
        int val = go(nums, 0, n-1);
        // cout<<val<<endl;
        return val >= (sum - val) ? true : false; 
    }
};
