// link :: https://leetcode.com/contest/weekly-contest-228/problems/minimum-limit-of-balls-in-a-bag/
class Solution {
public:
    
    bool check(vector<int>& nums, int mx, int mid){
        
        int cnt = 0;
        for(int i=0;i<nums.size();i++){
            if(nums[i] > mid){
                cnt += ((nums[i]+(mid-1))/mid) - 1;
            }
        }
        
        return cnt <= mx ? true : false;
    }
    
    int minimumSize(vector<int>& nums, int maxOperations) {
        
        long long low = 1, high = 1e10;
        int ans;
        
        while(low <= high)
        {
            int mid = low + (high - low)/2;
            if(check(nums, maxOperations, mid)){
                high = mid - 1;
                ans = mid;
            }
            else
            {
                low = mid + 1;
            }
        }
        return ans;
    }
};
