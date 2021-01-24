// link :: https://leetcode.com/problems/keys-and-rooms/
class Solution {
public:
    
    void dfs(int src, vector<vector<int>>& rooms, vector<bool> &vis)
    {
        vis[src] = 1;
        for(auto x : rooms[src])
        {
            if(!vis[x])
                dfs(x, rooms, vis);
        }
    }
    
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        
        int n = rooms.size();
        vector<bool> vis(n+1, false);
        
        dfs(0, rooms, vis);
        for(int i=0;i<n;i++)
        {
            if(vis[i] == false)
                return false;
        }
        return true;
    }
};
