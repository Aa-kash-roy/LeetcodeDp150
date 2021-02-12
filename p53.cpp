// link :: https://leetcode.com/problems/group-anagrams/
class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        
        map<string, map<char, int>> mp;
        for(auto x: strs){
            string temp = x;
            map<char, int> te;
            for(auto z: temp){
                te[z]++;
            }
            mp[temp] = te;
        }
        
        map<map<char, int>, vector<int>> reqd;
        for(int i=0;i<strs.size();i++){
            string x = strs[i];
            reqd[mp[x]].push_back(i);
        }
        
        vector<vector<string>> res;
        for(auto x: reqd){
            vector<int> temp = x.second;
            vector<string> ans;
            for(auto p: temp){
                ans.push_back(strs[p]);
            }
            res.push_back(ans);
        }
        return res;    
    }
};
