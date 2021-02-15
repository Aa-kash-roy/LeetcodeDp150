// link :: https://leetcode.com/problems/jump-game-iii/
class Solution {
public:
    
    vector<int> adj[50005];
    bool vis [50005];
    
    void dfs(int src){
        vis[src] = 1;
        for(auto x: adj[src]){
            if(!vis[x])
                dfs(x);
        }
    }
    
    bool canReach(vector<int>& arr, int start) {
        
        if(arr[start] == 0)
            return true;
        memset(vis, false, sizeof(vis));
        int n = arr.size(), src = start;
        vector<int> dest;
        for(int i=0;i<n;i++){
            
            if(arr[i] == 0){
                dest.push_back(i);
                continue;
            }
            if(i + arr[i] < n)
                adj[i].push_back(i + arr[i]);
            if(i - arr[i] >= 0)
                adj[i].push_back(i - arr[i]);
        }
        
        dfs(src);
        for(auto x: dest){
            if(vis[x])
                return true;
        }
        return false;
    }
};
