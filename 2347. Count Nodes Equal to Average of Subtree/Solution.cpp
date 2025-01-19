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
    pair<int,int> dfs(TreeNode* root,int &count){
        if(root==NULL){
            return make_pair(0,0);
        }

        pair<int,int> leftTree = dfs(root->left,count);
        pair<int,int> rightTree = dfs(root->right,count);

        int sum = root->val+leftTree.first+rightTree.first;
        int num = 1+leftTree.second+rightTree.second;
        if((sum/num)==root->val){
            count++;
        }
        return make_pair(sum,num);
    }
    int averageOfSubtree(TreeNode* root) {
        int count=0;
        dfs(root,count);
        return count;
    }
};