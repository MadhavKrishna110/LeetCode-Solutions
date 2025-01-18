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
    void dfs(TreeNode* node,int level,map<int,int> &mp){
        if(node==NULL) return;
        if(mp.find(level)==mp.end()){
            mp[level] = node->val;
        }
        dfs(node->right,level+1,mp);
        dfs(node->left,level+1,mp);

    }
    vector<int> rightSideView(TreeNode* root) {
        map<int,int> mp;
        dfs(root,0,mp);
        vector<int> v;
        for(auto i:mp){
            v.push_back(i.second);
        }
        return v;
    }
};