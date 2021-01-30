// link :: https://leetcode.com/problems/ones-and-zeroes/
class Solution {
public:
    
    int dp[605][105][105];
    int go(vector<pair<int, int>> &vp, int m, int n, int idx)
    {
        if(m < 0 || n < 0)
            return 0;
        if(idx == vp.size())
            return 0;
        
        if(dp[idx][m][n] != -1)
            return dp[idx][m][n];
        
        if(vp[idx].first <= m && vp[idx].second <= n)
        {
            return dp[idx][m][n] = max(1 + go(vp, m-vp[idx].first, n-vp[idx].second, idx+1), go(vp, m, n, idx+1));
        }
        else
            return dp[idx][m][n] = go(vp, m, n, idx+1);
    }
    
    int findMaxForm(vector<string>& strs, int m, int n) {
        
        vector<pair<int, int>> vp;
        for(auto x: strs)
        {
            int cnt0 = 0, cnt1 = 0; 
            for(int i=0;x[i];i++)
            {
                if(x[i] == '1')
                    cnt1++;
                else
                    cnt0++;
            }
            vp.push_back({cnt0, cnt1});
        }
        
        memset(dp, -1, sizeof(dp));
        return go(vp, m, n, 0);
    }
};
