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
    int widthOfBinaryTree(TreeNode* root) {
        
        queue<pair<TreeNode*,int>> q;
        q.push({root,0});
        long long ans=0;
        while(!q.empty()){
            long long size = q.size();
            long long first=q.front().second;
            long long last ;
            for(int i=0;i<size;i++){
                TreeNode* node = q.front().first;
                long long idx = q.front().second-first;
                if(i==size-1){
                    last = q.front().second;
                }

                q.pop();
                if(node->left){
                    q.push({node->left,2*idx});
                }
                if(node->right){
                    q.push({node->right,2*idx+1});
                }
            }
            ans = max(ans,last-first+1);
        }
        return ans;
    }
};