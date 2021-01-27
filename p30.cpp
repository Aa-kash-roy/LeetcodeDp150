// link :: https://leetcode.com/problems/trapping-rain-water/
class Solution {
public:
    int trap(vector<int>& height) {
        
        int n = height.size();
        if(n==0)
            return 0;
        int dpl[n+1], dpr[n+1];
        
        dpl[0] = height[0], dpr[n-1] = height[n-1];
        for(int i=1;i<n;i++)
            dpl[i] = max(dpl[i-1], height[i]);
        
        for(int i=n-2;i>=0;i--)
            dpr[i] = max(dpr[i+1], height[i]);
        
        int ans = 0;
        for(int i=1;i<n-1;i++)
        {
            ans += min(dpl[i],dpr[i]) - height[i];
        }
        return ans;
    }
};
