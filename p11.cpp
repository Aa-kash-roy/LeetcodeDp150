// link :: https://leetcode.com/problems/longest-arithmetic-subsequence/
class Solution {
public:
    int longestArithSeqLength(vector<int>& A) {
        
        int dp[1005][1005] = {0}, freq[1005] = {0};
        
        int n = A.size();
        for(int i=1;i<n;i++)
        {
            for(int j=0;j<i;j++){
                int val = 2*A[j] - A[i];
                if(val >= 0)
                {
                    if(freq[val])
                    {
                        dp[A[i]][A[j]] = 1 + dp[A[j]][val];
                    }
                    else
                    {
                        dp[A[i]][A[j]] = 2;
                    }
                }
                else
                    dp[A[i]][A[j]] = 2;
                
                freq[A[j]] = 1;
                //cout<<"at :: "<<i<<' '<<j<<' '<<dp[A[i]][A[j]]<<endl;
                    
            }  
            memset(freq, 0, sizeof(freq));
        }
        
        int ans = 0;
        for(int i=0;i<1002;i++)
        {
            for(int j=0;j<1002;j++)
                ans = max(ans, dp[i][j]);
        }
        
        return ans;
    }
};
