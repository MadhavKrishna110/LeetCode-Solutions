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
    void dfs(TreeNode* root,int level,vector<int> &depth,vector<TreeNode*> &node){
        if(root==NULL) return;
        if(!root->left && !root->right){
             depth.push_back(level);
        node.push_back(root);
        return;
        }

        depth.push_back(level);
        node.push_back(root);
        dfs(root->left,level+1,depth,node);
        depth.push_back(level);
        node.push_back(root);
        dfs(root->right,level+1,depth,node);
        depth.push_back(level);
        node.push_back(root);
    }
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        vector<int> depthArr;
        vector<TreeNode*> nodeArr;
        dfs(root,0,depthArr,nodeArr);
        int idx1=-1,idx2=-1;
        for(int i=0;i<nodeArr.size();i++){
            if(idx1==-1 && (nodeArr[i]==p || nodeArr[i]==q)){
                idx1=i;
            }
            if(idx1!=-1 && (nodeArr[i]==p || nodeArr[i]==q)){
                idx2=i;
            }
        }
        int minDepth=INT_MAX,idx=-1;
        for(int j=idx1;j<=idx2;j++){
            cout<<nodeArr[j]->val<<"-"<<depthArr[j]<<endl;
            if(depthArr[j]<minDepth){
                minDepth = depthArr[j];
                idx = j;
            }
        }
        return nodeArr[idx];
    }
};