// link :: https://leetcode.com/problems/minimum-number-of-removals-to-make-mountain-array/
class Solution {
public:
    int minimumMountainRemovals(vector<int>& nums) {
        
        int n = nums.size();
        int dpl[n], dpr[n];
        
        for(int i=0;i<n;i++){
            dpl[i] = 1;
            for(int j=0;j<i;j++){
                if(nums[i] > nums[j])
                    dpl[i] = max(dpl[i], dpl[j]+1);
            }
        }
        
        for(int i=n-1;i>=0;i--){
            dpr[i] = 1;
            for(int j=n-1;j>i;j--){
                if(nums[i] > nums[j])
                    dpr[i] = max(dpr[i], dpr[j]+1);
            }
        }
        
        int mx = 0;
        for(int i=1;i<n-1;i++){
            // cout<<dpl[i]<<" ==> "<<dpr[i]<<endl;
            mx = max(mx, dpl[i]+dpr[i]);
        }
        
        // cout<<mx<<endl;
        return n-(mx-1);
    }
};
