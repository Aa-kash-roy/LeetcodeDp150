// link :: https://leetcode.com/problems/rotting-oranges/
class Solution {
public:
    int x_mov[4] = {1, -1, 0, 0};
    int y_mov[4] = {0, 0, 1, -1};
    
    bool is_valid(int x, int y, int n, int m)
    {
        if(x < 0 || x >= n || y < 0 || y >= m)
            return false;
        return true;
    }
    
    int orangesRotting(vector<vector<int>>& grid) {
        
        int n=grid.size();
        int m=grid[0].size();
        int dp[n][m], vis[n][m];
        
        memset(vis, 0, sizeof(vis));
        queue<pair<int, int>> q;
        
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j] == 2){
                    q.push({i, j});
                    dp[i][j] = 0;
                    vis[i][j] = 1;
                }
                else
                    dp[i][j] = INT_MAX;
            }
        }
        
        while(!q.empty()){
            pair<int, int> p = q.front();
            q.pop();
            for(int i=0;i<4;i++){
                int new_x = p.first + x_mov[i], new_y = p.second + y_mov[i];
                
                if(is_valid(new_x, new_y, n, m) && grid[new_x][new_y] == 1 && !vis[new_x][new_y]){
        
                    dp[new_x][new_y] = min(dp[p.first][p.second] + 1, dp[new_x][new_y]);
                    vis[new_x][new_y] = 1;
                    q.push({new_x, new_y});
                }
            }
        }
        
        int ans = INT_MIN;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j] == 1 && dp[i][j] == INT_MAX)
                    return -1;
                if(dp[i][j] != INT_MAX)
                { 
                    ans = max(ans, dp[i][j]);
                }    
            }
        }
        return ans != INT_MIN ? ans : 0;
    }
};
