// link :: https://leetcode.com/problems/word-break/
class Solution {
public:
    
    bool go(int i, string &s, vector<string>& wordDict, vector<int> &dp){
        
        if(i == s.length())
            return true;
        if(dp[i] != -1)
            return dp[i];
        bool ans = false;
        
        for(auto x: wordDict){
            int sz = x.length();
            string temp = s.substr(i, sz);
            if(temp == x)
                ans |= go(i+sz, s, wordDict, dp);
        }
        return dp[i] = ans;
    }
    
    bool wordBreak(string s, vector<string>& wordDict) {
        
        vector<int> dp(s.length(), -1);
        return go(0, s, wordDict, dp);
    }
};
