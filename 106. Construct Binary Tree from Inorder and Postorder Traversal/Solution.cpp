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
    TreeNode* buildTree(vector<int> inorder,int instart,int inend,vector<int> postorder,int poststart,int postend,map<int,int> &mp){
        if(instart>inend || poststart>postend){
            return NULL;
        }

        TreeNode* root = new TreeNode(postorder[postend]);
        int inRoot = mp[postorder[postend]];
        int nums = inend-inRoot;
        root->right = buildTree(inorder,inRoot+1,inend,postorder,postend-nums,postend-1,mp);
        root->left = buildTree(inorder,instart,inRoot-1,postorder,poststart,postend-nums-1,mp);

        return root;

    }
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        map<int,int> mp;
        int n = inorder.size();
        for(int i=0;i<n;i++){
            mp[inorder[i]]=i;
        }

        return buildTree(inorder,0,n-1,postorder,0,n-1,mp);
    }
};