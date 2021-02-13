// link :: https://leetcode.com/problems/shortest-path-in-binary-matrix/
class Solution {
public:
    int x_mov[8] = {1, 1, 1, 0, 0, -1, -1, -1};
    int y_mov[8] = {-1, 0, 1, -1, 1, -1, 0, 1};
    
    bool is_valid(int x, int y, int n){
        if(x<0 || y<0 || x>=n || y>=n)
            return false;
        return true;
    }
    
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        
        int n = grid.size();
        if(grid[0][0] == 1 || grid[n-1][n-1] == 1)
            return -1;
        int dp[n][n];
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++)
                dp[i][j] = INT_MAX;
        }
        
        dp[0][0] = 1;
        
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                
                if(i==0 && j==0){
                    dp[i][j] = 1;
                    if(!grid[i][j]){
                       for(int k=0;k<8;k++){
                           int new_x = i + x_mov[k], new_y = j + y_mov[k];
                           if(is_valid(new_x, new_y, n) && !grid[new_x][new_y] && dp[i][j] != INT_MAX){
                               dp[new_x][new_y] = min(dp[new_x][new_y], (1 + dp[i][j]));
                           }
                       }
                   } 
                }
                else
                {
                   if(!grid[i][j]){
                       for(int k=0;k<8;k++){
                           int new_x = i + x_mov[k], new_y = j + y_mov[k];
                           if(is_valid(new_x, new_y, n) && !grid[new_x][new_y] && dp[i][j] != INT_MAX){
                               dp[new_x][new_y] = min(dp[new_x][new_y], (1 + dp[i][j]));
                           }
                       }
                   } 
                }
            }
        }
        
        if(dp[n-1][n-1] != INT_MAX)
            return dp[n-1][n-1];
        return -1;
    }
};
