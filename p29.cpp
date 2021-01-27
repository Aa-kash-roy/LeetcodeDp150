// link :: https://leetcode.com/problems/longest-palindromic-substring/

class Solution {
public:
    string longestPalindrome(string s) {
        
        int n = s.length();
        int dp[n+1][n+1];
        memset(dp, 0, sizeof(dp));
        
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<=n;j++)
            {
                if(i==j)
                    dp[i][j] = 1;
                if(j-i == 1)
                {
                    if(s[i] == s[j])
                        dp[i][j] = 2;
                }   
            }
        }
        
        for(int sz = 2; sz < n; sz++)
        {
            for(int i=0;i<(n-sz);i++)
            {
                int j = i+sz;
                if(s[i] == s[j] && dp[i+1][j-1])
                    dp[i][j] = 2 + dp[i+1][j-1];
            }
        }
        
        pair<int, int> p = {0, 0};
        int mx = 0;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(dp[i][j] > mx){
                    mx = dp[i][j];
                    p = {i, j};
                }
            }
        }
        
        string res = "";
        for(int i=p.first; i<=p.second;i++)
            res += s[i];
        
        return res;
    }
};
