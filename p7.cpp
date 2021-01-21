// Link :: https://leetcode.com/problems/minimum-falling-path-sum/

class Solution {
public:
    
    int dp[105][105];
    int go(vector<vector<int>>& A, int idx, int col)
    {
        if(col == A.size())
            return 0;
        
        if(dp[idx][col] != -1)
            return dp[idx][col];
        int op1, op2, op3;
        op1 = op2 = op3 = INT_MAX;
        if(idx-1 >= 0)
            op1 = go(A, idx-1, col+1);
        if(idx+1 < A.size())
            op2 = go(A, idx+1, col+1);
        
        op3 = go(A, idx, col+1);
        return dp[idx][col] = A[col][idx] + min({op1, op2, op3});
    }
    
    int minFallingPathSum(vector<vector<int>>& A) {
        
        memset(dp, -1, sizeof(dp));
        int ans = INT_MAX;
        for(int i=0;i<A[0].size();i++)
        {
            int tempAns = go(A, i, 0);
            ans = min(ans, tempAns);
        }
        return ans;
    }
};
