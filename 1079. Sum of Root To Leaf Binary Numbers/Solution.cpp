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
    void solve(TreeNode* root,int level,string pathSum,int &sum){
        if(root==NULL) return ;
        if(root->left==NULL && root->right==NULL){
           int value = 0;
           pathSum+=to_string(root->val);
           int n = pathSum.size();
           for(int i=n-1;i>=0;i--){
            if(pathSum[i]=='1'){
                value+=pow(2,n-1-i);
            }
           }
           cout<<value<<"-"<<root->val<<endl;
           sum+=value;
            return;
        }
        pathSum+=to_string(root->val);
        solve(root->left,level+1,pathSum,sum);
        solve(root->right,level+1,pathSum,sum);
    }
    int sumRootToLeaf(TreeNode* root) {
        int sum=0;
        solve(root,0,"",sum);
        return sum;
    }
};