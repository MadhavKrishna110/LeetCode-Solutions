/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    void getPath(TreeNode* root,TreeNode* p, TreeNode* q,vector<TreeNode*> &res,vector<vector<TreeNode*>> &ans){
        if(root==NULL) return;
        res.push_back(root);
        if(root==p || root==q){ 
            ans.push_back(res);     
        } 
        getPath(root->left,p,q,res,ans);
        getPath(root->right,p,q,res,ans);
        res.pop_back();


    }
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        vector<vector<TreeNode*>> ans;
        vector<TreeNode*> res;
        getPath(root,p,q,res,ans);
        int i=0;
        while(i<ans.size()){
            int j=0;
            while(j<ans[i].size()){
                cout<<ans[i][j]->val<<" ";
                j++;
            }
            cout<<endl;
            i++;
        }
        cout<<ans.size()<<endl;
        int temp=0;
        while(temp<min(ans[0].size(),ans[1].size()) && ans[0][temp]==ans[1][temp]){
            temp++;
        }
        return ans[0][temp-1];
    }
};