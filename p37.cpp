// link :: https://leetcode.com/problems/continuous-subarray-sum/
class Solution {
public:
    bool checkSubarraySum(vector<int>& nums, int k) {
        
        if(k==0){
            
            int cnt = 0;
            if(nums.size() == 1)
                return false;
            for(int i=0;i<nums.size();i++)
            {
                if(nums[i] == 0 && nums[i+1] == 0)
                    return true;
            }
            return false;
        }
        map<int, int> mp;
        mp[0] = -1;
        int sum = 0;
        bool ok = false;
        for(int i=0;i<nums.size();i++)
        {
            sum += nums[i];
            sum %= k;
            
            if(mp.count(sum))
            {
                if(i - mp[sum] >= 2){
                    ok = true;
                    break;
                }
            }
            else
            {
                mp[sum] = i;
            }
        }
        if(ok)
            return true;
        return false;
    }
};
