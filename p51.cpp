// link :: https://leetcode.com/problems/student-attendance-record-ii/
class Solution {
public:
    
    int dp[100005][2][3], mod = 1e9+7;
    long long go(int i, int a, int lc, int n)
    {
        if(i==n)
            return 1;
        
        if(dp[i][a][lc] != -1)
            return dp[i][a][lc]%mod;
        if(!a){
            if(lc == 2){
                return dp[i][a][lc] = (go(i+1, 1, 0, n)%mod + go(i+1, a, 0, n)%mod)%mod;
            }
            else
                return dp[i][a][lc] = (go(i+1, 1, 0, n)%mod + go(i+1, a, 0, n)%mod + go(i+1, a, lc+1, n)%mod)%mod;
        }
        else
        {
            if(lc == 2){
                return dp[i][a][lc] = go(i+1, a, 0, n)%mod;
            }
            else
                return dp[i][a][lc] = (go(i+1, a, 0, n)%mod + go(i+1, a, lc+1, n)%mod)%mod;
        }
    }
    
    int checkRecord(int n) {
        
        memset(dp, -1, sizeof(dp));
        return go(0, 0, 0, n)%mod;
    }
};
