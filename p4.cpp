// link :: https://leetcode.com/contest/weekly-contest-223/problems/minimize-hamming-distance-after-swap-operations/
class Solution {
public:
    
    vector<int> bfs(int src, vector<int> adj[], vector<bool> &vis){
        vector<int> temp;
        vis[src] = true;
        queue<int> q;
        q.push(src);
        temp.emplace_back(src);
        
        while(!q.empty()){
            int node = q.front();
            q.pop();
            for(auto x:adj[node]){
                if(!vis[x]){
                    temp.emplace_back(x);
                    q.push(x);
                    vis[x] = true;
                }
            }
        }
        return temp;
    }
    
    int minimumHammingDistance(vector<int>& source, vector<int>& target, vector<vector<int>>& allowedSwaps) {
        
        int len = source.size();
         vector<int> adj[len+1];
         vector<bool> vis(len+1, false);
        for(int i=0;i<=len;i++){
            adj[i].clear();
        }
        for(auto x:allowedSwaps){
            vector<int> temp = x;
            adj[temp[0]].emplace_back(temp[1]);
            adj[temp[1]].emplace_back(temp[0]);
        }
        
        int cnt = 0;
        vector<vector<int>> reqd;
        for(int i=0;i<=len;i++){
            if(!vis[i]){
                vector<int> temp = bfs(i, adj, vis); 
                if(temp.size() > 1){
                    unordered_map<int, int> mp;
                for(auto y:temp){
                    mp[source[y]]++;
                }
                for(auto y:temp){
                    if(mp.find(target[y]) != mp.end()){
                        mp[target[y]]--;
                    }
                }
            
                 int tempCount = 0;
                 for(auto x:mp){
                 if(x.second > 0)
                    tempCount += x.second;
                 }
                    cnt += tempCount;
                    
                }
                else
                {
                    if(i<source.size()){
                        if(source[i] != target[i])
                            cnt++;
                    }
                }
            }
        }
        
        return cnt;
    }
};
