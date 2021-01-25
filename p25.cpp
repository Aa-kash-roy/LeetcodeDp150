// link :: https://leetcode.com/problems/knight-dialer/
class Solution {
public:
    
    int mod = 1e9 + 7;
    int mat[4][3] = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}, {-1, 0, -2}};
    int x_mov[8] = {-2, -2, -1, -1, 1, 1, 2, 2};
    int y_mov[8] = {-1, 1, -2, 2, -2, 2, 1, -1};
    
    map<pair<int, int>, vector<pair<int, int>>> mp;
    bool is_valid(int x, int y)
    {
        if(x<0 || x>=4 || y<0 || y>=3 || mat[x][y] < 0)
            return false;
        return true;
    }
    
    int go(int x, int y, int pos, int n, vector<vector<vector<int>>> &dp)
    {
        if(pos == n)
            return 1;
        if(dp[pos][x][y] != -1)
            return dp[pos][x][y];
        
        vector<pair<int, int>> vec = mp[{x, y}];
        
        int ans = 0;
        for(auto x: vec)
        {
            ans += go(x.first, x.second, pos+1, n, dp);
            ans %= mod;
        }
        return dp[pos][x][y] = ans%mod;
    }
    
    int knightDialer(int n) {
        
        vector<vector<vector<int> > > dp (n+1,vector<vector<int> >(4,vector <int>(3,-1)));
        int ans = 0;
        
        for(int i=0;i<4;i++)
        {
            for(int j=0;j<3;j++)
            {
                vector<pair<int, int>> vec;
                for(int k=0;k<8;k++)
                {
                    int new_x = i + x_mov[k];
                    int new_y = j + y_mov[k];
                    if(is_valid(new_x, new_y))
                        vec.push_back({new_x,new_y});
                }
                mp[{i, j}] = vec;
            }
        }
        
        for(int i=0;i<4;i++){
            for(int j=0;j<3;j++)
            {
                if(mat[i][j] >= 0)
                {
                    ans += go(i, j, 1, n, dp);
                    ans %= mod;
                }
            }
        }
        return ans%mod;
    }
};
