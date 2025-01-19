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
    int pathSum(TreeNode* root,int &maxSum){
        if(root==NULL){
            return -1e9;
        }
        if(root->left==NULL && root->right==NULL){
            return root->val;
        }

        int left = pathSum(root->left,maxSum);
        int right = pathSum(root->right,maxSum);
        maxSum = max(maxSum,max(root->val+left+right,max(left,right)));
        maxSum = max(max(max(left,right)+root->val,root->val),maxSum);
        return max(max(left,right)+root->val,root->val);
    }
    int maxPathSum(TreeNode* root) {
        if(root==NULL) return 0;
        if(root->left==NULL && root->right==NULL) return root->val;
        int maxm = INT_MIN;
        pathSum(root,maxm);
        return maxm;
        
    }
};