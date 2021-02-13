
// link :: https://leetcode.com/problems/find-largest-value-in-each-tree-row/
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
    long long INF = 1e18;
    vector<int> largestValues(TreeNode* root) {
        
        vector<int> ans;
        if(root == NULL)
            return ans;
        queue<TreeNode*> q1;
        queue<long long> q2;
        q1.push(root);
        q2.push(root->val);
        q2.push(INF);
        
        int mx = INT_MIN;
        while(q2.size() > 1){
            
            long long val = q2.front();
            q2.pop();
            if(val == INF){
                ans.push_back(mx);
                mx = INT_MIN;
                q2.push(INF);
                continue;
            }
            else
            {
                mx = max(mx,(int) val);
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
        ans.push_back(mx);
        return ans;
    }
};
