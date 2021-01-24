// link :: https://leetcode.com/problems/find-kth-largest-xor-coordinate-value/
class Solution {
public:
    int kthLargestValue(vector<vector<int>>& matrix, int k) {
        
        int n = matrix.size(), m = matrix[0].size();
        vector<vector<int>> res(n, vector<int>(m, 0));
        res[0][0] = matrix[0][0];
        
        for(int i=1;i<m;i++)
            res[0][i] = res[0][i-1]^matrix[0][i];
        
        for(int i=1;i<n;i++)
            res[i][0] = res[i-1][0]^matrix[i][0];

        for(int i=1;i<n;i++)
        {
            for(int j=1;j<m;j++)
            {
                res[i][j] = res[i-1][j]^res[i][j-1]^matrix[i][j]^res[i-1][j-1];
            }
        }
        
        vector<int> ans;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++){
                // cout<<res[i][j]<<' ';
                ans.push_back(res[i][j]);
            }
            // cout<<endl;
        }
        sort(ans.begin(), ans.end());
        reverse(ans.begin(), ans.end());
        return ans[k-1];
    }
};
