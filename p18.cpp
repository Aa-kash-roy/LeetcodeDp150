// link :: https://leetcode.com/problems/wildcard-matching/
class Solution {
    public:
    
    bool go(string &s, string &p, int i1, int i2, vector<vector<int>> &dp)
    {
        if(i1 == s.length() && i2 == p.length()){
            return true;
        }
        if(i1 == s.length())
        {
            for(int i=i2;i<p.size();i++)
            {
                if(p[i] != '*')
                    return false;
            }
            return true;
        }
        if(i2 == p.length()){
            return false;  
        }
        if(dp[i1][i2] != -1)
            return dp[i1][i2];
        if(!(p[i2] == '?' || p[i2] == '*')){
            if(p[i2] == s[i1]){
                return dp[i1][i2] = go(s, p, i1+1, i2+1, dp);
            }
            else
                return dp[i1][i2] = false;
        }
        else
        {
            if(p[i2] == '?')
            {
                return dp[i1][i2] = go(s, p, i1+1, i2+1, dp);
            }
            else
                return dp[i1][i2] = go(s, p, i1, i2+1, dp) || go(s, p, i1+1, i2+1, dp) || go(s, p, i1+1, i2, dp);
        }
    }
    
    bool isMatch(string s, string p) {
        
        vector<vector<int>> dp(s.length()+2, vector<int>(p.length()+2, -1));
        
        return go(s, p, 0, 0, dp);
    }
};
