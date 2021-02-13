// link :: https://leetcode.com/problems/find-bottom-left-tree-value/submissions/
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    long long INF = 1e13;
    int findBottomLeftValue(TreeNode* root) {
        
        vector<vector<int>> ans;

        queue<TreeNode*> q1;
        queue<long long> q2;
        q1.push(root);
        q2.push(root->val);
        q2.push(INF);
        
        vector<int> temp;
        while(q2.size() > 1){
            
            long long val = q2.front();
            q2.pop();
            if(val == INF){
                ans.push_back(temp);
                q2.push(INF);
                temp.clear();
                continue;
            }
            else
            {
                temp.push_back(val);
            }
            TreeNode *temp = q1.front();
            q1.pop();
            if(temp->left){
                q2.push(temp->left->val);
                q1.push(temp->left);
            }
            if(temp->right)
            {
                q2.push(temp->right->val);
                q1.push(temp->right);
            }
        }
        ans.push_back(temp);
        int n = ans.size();
        return (int)ans[n-1][0];
    }
};
