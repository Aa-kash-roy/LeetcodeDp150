// link :: https://leetcode.com/problems/triangle/
class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        
        int n = triangle.size();
        vector<vector<int>> dp(n, vector<int> (n, 0));
        dp[0][0] = triangle[0][0];
    
        for(int i=1;i<n;i++){
            for(int j=0;j<triangle[i].size();j++){
                if(j == 0 ){
                    dp[i][j] = triangle[i][j] + dp[i-1][j];
                }
                else if(j == triangle[i].size() - 1){
                    dp[i][j] = triangle[i][j] + dp[i-1][j-1];
                }
                else
                    dp[i][j] = triangle[i][j] + min(dp[i-1][j-1], dp[i-1][j]);
            }
        }
      
        int ans = INT_MAX;
        for(auto x: dp[n-1])
            ans = min(ans, x);
        return ans;
    }
};
