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
    int dfs(TreeNode* root,int maxNode){
        if(root==NULL) return 0;
        int left = dfs(root->left,max(root->val,maxNode));
        int right = dfs(root->right,max(root->val,maxNode));

        if(root->val>=maxNode){
            return 1+left+right;
        } else {
            return left+right;
        }
    }
    int goodNodes(TreeNode* root) {
        return dfs(root,INT_MIN);
    }
};