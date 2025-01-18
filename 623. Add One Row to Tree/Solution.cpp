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
    TreeNode* addOneRow(TreeNode* root, int val, int depth) {
       if(depth==1) {
        TreeNode* newNode = new TreeNode(val,root,nullptr);
        return newNode;
       }
        queue<pair<TreeNode*,int>> q;
        q.push({root,1});
        while(!q.empty()){

            TreeNode* node = q.front().first;
            int level = q.front().second;
            if(level>=depth) break;
            q.pop();

            if(level==depth-1){
                TreeNode* leftTree = node->left;
                TreeNode* rightTree = node->right;
                TreeNode* newLeftNode = new TreeNode(val,leftTree,nullptr);
                TreeNode* newRightNode = new TreeNode(val,nullptr,rightTree);
                node->left = newLeftNode;
                node->right = newRightNode;
            }

            if(node->left){
                q.push({node->left,level+1});
            }
            if(node->right){
                q.push({node->right,level+1});
            }

        }
        return root;
    }
};