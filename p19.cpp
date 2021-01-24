// link :: https://leetcode.com/problems/longest-string-chain/
class Solution {
public:
    
    bool check(string &a, string &b)
    {
        int idx = 0, cnt = 0;
        for(int i=0;b[i];i++)
        {
            if(a[idx] == b[i])
                idx++;
            else{
                cnt++;
                if(cnt > 1)
                    return false;
            }
            
        }
        
        return (cnt == 1 && idx == a.length()) ? true : false;
    }
    
    int longestStrChain(vector<string>& words) {
        
        sort(words.begin(), words.end(), [](string a, string b){
           return a.length() < b.length(); 
        });
        int n = words.size();
        
        vector<int> dp(n, 0);
        for(int i=0;i<n;i++)
        {
            dp[i] = 1;
            for(int j=0;j<i;j++)
            {
                if(check(words[j], words[i]))
                {
                    dp[i] = max(dp[i], 1 + dp[j]);
                }
            }
        }
        int ans = 0;
        for(int i=0;i<n;i++)
            ans = max(ans, dp[i]);
        return ans;
    }
};
