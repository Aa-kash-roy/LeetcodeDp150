
// link :: https://leetcode.com/problems/convert-bst-to-greater-tree/
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
    vector<int> pre;
    map<int, int> mp;
    void preorder(TreeNode* root){
        if(!root)
            return;
        preorder(root->left);
        pre.push_back(root->val);
        preorder(root->right);
    }
    
    TreeNode* convertBST(TreeNode* root) {
        
        if(root == NULL)
            return NULL;
        preorder(root);
        int sum = pre.back();
        mp[sum] = sum;
        for(int i=pre.size()-2;i>=0;i--){
            mp[pre[i]] = pre[i] + sum;
            sum = mp[pre[i]];
        }
        
        queue<TreeNode*> q;
        q.push(root);
        
        while(!q.empty())
        {
            TreeNode* temp = q.front();
            temp->val = mp[temp->val];
            q.pop();
            if(temp->left){
                q.push(temp->left);
            }
            if(temp->right)
                q.push(temp->right);
        }
        
        return root;
    }
};
