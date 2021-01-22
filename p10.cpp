// link :: https://leetcode.com/problems/video-stitching/

class Solution {
public:
    
    int dp[105][105];
    int go(vector<vector<int>> clips, int t, int idx, int last)
    {
        if(clips[last][1] >= t)
            return 0;
        if(idx == clips.size())
            return 1000007;
        if(dp[idx][last] != -1)
            return dp[idx][last];
        if(clips[last][1] >= clips[idx][0])
        {
            if(clips[idx][1] >= t)
                return 1;
          
            return dp[idx][last] = min( 1 + go(clips, t, idx+1, idx), go(clips, t, idx+1, last));
        }
        
        return dp[idx][last] = go(clips, t, idx+1, last);
    }
    
    int videoStitching(vector<vector<int>>& clips, int T) {
        
        memset(dp, -1, sizeof(dp));
        sort(clips.begin(), clips.end(), [](vector<int> t1, vector<int> t2){
            
            if(t1[0] == t2[0])
                return t1[1] < t2[1];
            return t1[0] < t2[0];
        });
        
        if(T==0)
            return 0;
        if(clips[0][0] != 0)
            return -1;
        
        int ans = INT_MAX;
        for(int i=0;clips.size();i++)
        {
            if(clips[i][0] != 0)
                break;
            else
                ans = min(ans, 1 + go(clips, T, i+1, i));
        }
        return ans >= 1000007 ? -1 : ans;
    }
};
