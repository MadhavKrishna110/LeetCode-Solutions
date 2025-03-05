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


    // int findHeight(TreeNode * root){
    //     if(root==NULL)
    //         return 0;
    //     return max(findHeight(root->left), findHeight(root->right))+1;
    // }


    int fn(TreeNode* root){
        if(root==NULL)
            return 0;
        
        int left_ht=fn(root->left);
        if(left_ht==-1)
            return -1;
        int right_ht=fn(root->right);
        if(right_ht==-1)
            return -1;
        
        if(abs(left_ht-right_ht)>1)
            return -1;
        else 
            return max(left_ht,right_ht)+1;

    }


    bool isBalanced(TreeNode* root) {
        if(root==NULL)
            return true;

        int ht=fn(root);
        return ht==-1?false:true;


        // Below sol^n fails on TC - [1,null,2,null,3]
        // int left_ht=findHeight(root->left);
        // int right_ht=findHeight(root->right);

        // return abs(left_ht-right_ht<=1 && 
        //     isBalanced(root->left) && isBalanced(root->right));
    }
};