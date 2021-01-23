// link :: https://leetcode.com/explore/challenge/card/january-leetcoding-challenge-2021/582/week-4-january-22nd-january-28th/3614/
class Solution {
public:
    vector<vector<int>> diagonalSort(vector<vector<int>>& mat) {
        
        map<int, vector<int>> mp;
        for(int i=0;i<mat.size();i++){
            for(int j=0;j<mat[0].size();j++){
                mp[i-j].push_back(mat[i][j]);
            }
        }
        
        for(auto x: mp)
        {
            vector<int> temp = x.second;
            sort(temp.begin(), temp.end());
            temp.push_back(0);
            mp[x.first] = temp;
        }

        vector<vector<int>> res(mat.size(), vector<int>(mat[0].size(), 0));
        for(int i=0;i<mat.size();i++){
            for(int j=0;j<mat[0].size();j++){
                
                vector<int> temp = mp[i-j];
                int sz = temp.size();
                res[i][j] = temp[temp[sz-1]];
                temp[sz-1]++;
                mp[i-j] = temp;
            }
        }
        return res;
    }
};
