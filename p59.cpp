// link :: https://leetcode.com/problems/maximum-level-sum-of-a-binary-tree/
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
    int maxLevelSum(TreeNode* root) {
        
        queue<TreeNode*> q1;
        q1.push(root);
        q1.push(NULL);
        
        int label = 1, sum = 0, mx = INT_MIN, ans = 1;
        while(q1.size() > 1){
            
            TreeNode *temp = q1.front();
            q1.pop();
            if(temp == NULL){
                if(sum > mx){
                    ans = label;
                    mx = sum;
                }
                label++;
                q1.push(NULL);
                sum = 0;
                continue;
            }
            else
            {
                sum += temp->val;
            }
            
            if(temp->left){
                q1.push(temp->left);
            }
            if(temp->right)
            {
                q1.push(temp->right);
            }
        }
        
       if(sum > mx){
            ans = label;
            mx = sum;
        }
        return ans;
    }
};
