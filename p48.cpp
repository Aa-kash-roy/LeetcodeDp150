// link :: https://leetcode.com/contest/weekly-contest-198/problems/number-of-nodes-in-the-sub-tree-with-the-same-label/
class Solution {
public:
    
    vector<unordered_map<char, int>> mp;
    unordered_map<char, int> dfs(int src, int par, string &labels, vector<int> adj[])
    {
        mp[src][labels[src]]++;
        
        for(auto x: adj[src]){
            if(x!=par){ 
                unordered_map<char, int> temp = dfs(x, src, labels, adj);
                for(auto ch: temp){
                    mp[src][ch.first] += (ch.second);
                }
            }
        }
        return mp[src];
    }
    
    vector<int> countSubTrees(int n, vector<vector<int>>& edges, string labels) {
        
        vector<int> adj[n];
        for(int i=0;i<edges.size();i++){
            vector<int> temp = edges[i];
            adj[temp[0]].push_back(temp[1]);
            adj[temp[1]].push_back(temp[0]);
        }
        
        mp.resize(n+1);
        dfs(0, -1, labels, adj);
        vector<int> res;
        for(int i=0;i<labels.size();i++){
            int val = mp[i][labels[i]];
            res.push_back(val);
        }
        return res;
    }
};
