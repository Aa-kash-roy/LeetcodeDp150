// link :: https://leetcode.com/problems/edit-distance/
class Solution {
public:
    
    int dp[505][505];
    int go(string &s1, string &s2, int i, int j){
        
        if(i == s1.length() || j == s2.length()){
            if( i == s1.length())
                return s2.length() - j;
            else
                return s1.length() - i;
        }
        
        if(dp[i][j] != -1)
            return dp[i][j];
        
        if(s1[i] == s2[j]){
            return dp[i][j] = go(s1, s2, i+1, j+1);
        }
        else
            return  dp[i][j] = 1 + min(go(s1, s2, i+1, j+1), min(go(s1, s2, i+1, j), go(s1, s2, i, j+1)));
    }
    
    int minDistance(string word1, string word2) {
        
        memset(dp, -1, sizeof(dp));
        return go(word1, word2, 0, 0);
    }
};
