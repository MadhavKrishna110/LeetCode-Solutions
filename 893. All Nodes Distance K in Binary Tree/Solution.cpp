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
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        unordered_map<TreeNode*,TreeNode*> parentMap;

        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty()){
            TreeNode* node = q.front();
            q.pop();
            if(node->left){
                parentMap[node->left]=node;
                q.push(node->left);
            }
            if(node->right){
                parentMap[node->right]=node;
                q.push(node->right);
            }
        }

        queue<pair<TreeNode*,int>> qt;
        vector<int> visited(parentMap.size()+2,0);
        vector<int> ans;
        if(!root) return ans;
       // if(root->left ==NULL && root->right==NULL && root == target )
        qt.push({target,0});
        while(!qt.empty()){
            TreeNode* node = qt.front().first;
            int dist = qt.front().second;
            qt.pop();
            cout<<node->val<<"-"<<dist<<endl;
           if(!visited[node->val]){
                if(node->left && !visited[node->left->val]){
                    qt.push({node->left,dist+1});
                }
                if(node->right && !visited[node->right->val]){
                    qt.push({node->right,dist+1});
                }
                if(parentMap.find(node)!=parentMap.end() && !visited[parentMap[node]->val]){
                    qt.push({parentMap[node],dist+1});
                }
           }
           visited[node->val]=1;
           if(dist==k){
            ans.push_back(node->val);
           }

        }
        return ans;

    }
};