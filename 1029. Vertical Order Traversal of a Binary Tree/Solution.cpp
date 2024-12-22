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
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        map<int,map<int,multiset<int>>> mp;
        queue<pair<TreeNode*,pair<int,int>>> q;
        q.push(make_pair(root,make_pair(0,0)));
        
        while(!q.empty()){
            TreeNode* node = q.front().first;
            pair<int,int> coordinates = q.front().second;
            mp[coordinates.first][coordinates.second].insert(node->val);
            q.pop();

            if(node->left!=nullptr){
                q.push(make_pair(node->left,make_pair(coordinates.first-1,coordinates.second+1)));
            }
            if(node->right!=nullptr){
                q.push(make_pair(node->right,make_pair(coordinates.first+1,coordinates.second+1)));
            }
        }
        vector<vector<int>> ans;
        for(auto i:mp){
            vector<int> col;
            for(auto j:i.second){
                col.insert(col.end(),j.second.begin(),j.second.end());
            }
            ans.push_back(col);
        }
        return ans;

    }
};