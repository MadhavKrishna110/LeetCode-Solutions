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
    TreeNode* reverseOddLevels(TreeNode* root) {
        if(root==NULL) return root;
        queue<TreeNode*> q;
        q.push(root);
        vector<int> v;
        int level=0;
        while(!q.empty()){
            int n= q.size();
            vector<int> temp;
            for(int i=0;i<n;i++){
                TreeNode* node = q.front();
                q.pop();
                if(level%2!=0){
                    node->val = v[n-i-1];
                }
                
                if(node->left){
                    temp.push_back(node->left->val);
                    q.push(node->left);
                }
                if(node->right){
                    temp.push_back(node->right->val);
                    q.push(node->right);
                }

            }
            level++;
            v=temp;
        }
        return root;
    }
};