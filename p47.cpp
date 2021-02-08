// link :: https://leetcode.com/problems/maximal-square/
class Solution {
public:
    int maximalSquare(vector<vector<char>>& matrix) {
        
        int dp[301][301] = {0};
        int n = matrix.size(), m = matrix[0].size();
        int ans = 0;
        for(int i=0;i<m;i++){
            if(matrix[0][i] == '1')
                dp[0][i] = 1;
            ans = max(ans, dp[0][i]);
        }
        
        
        for(int i=0;i<n;i++){
            if(matrix[i][0] == '1')
                dp[i][0] = 1;
            ans = max(ans, dp[i][0]);
        }
        
        for(int i=1;i<n;i++){
            for(int j=1;j<m;j++){
                if(matrix[i][j] == '1'){
                    dp[i][j] = min({dp[i-1][j-1], dp[i-1][j], dp[i][j-1]}) + 1;
                    ans = max(ans, dp[i][j]);
                }
            }
        }
        
        return ans*ans;
    }
};
