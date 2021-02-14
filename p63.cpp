// link :: https://leetcode.com/explore/challenge/card/february-leetcoding-challenge-2021/585/week-2-february-8th-february-14th/3639/
class Solution {
public:
    
    vector<int> adj[105];
    int color[105], vis[105];
    bool go(int src, int par, int col){
        
        // cout<<src<<' '<<par<<" "<<col<<endl;
        vis[src] = 1;
        color[src] = col;
        for(auto ch: adj[src]){
            if(!vis[ch] && !go(ch, src, col^1)){
                return false;
            }
            else{
                if(color[ch] == color[src])
                    return false;
            }
        }
        return true;
    }
    
    bool isBipartite(vector<vector<int>>& graph) {
        
        memset(vis, 0, sizeof(vis));
        memset(color, -1, sizeof(color));
        for(int i=0;i<graph.size();i++)
        {
            vector<int> temp = graph[i];
            for(auto x: temp){
                adj[i].push_back(x);
            }
        }
        bool ok = true;
        for(int i=0;i<graph.size();i++){
            if(!vis[i]){
                ok = go(i, -1, 0);
                if(!ok)
                    return false;
            }
        }
        return ok;
    }
};
