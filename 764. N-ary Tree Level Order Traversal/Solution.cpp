/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/

class Solution {
public:
    vector<vector<int>> levelOrder(Node* root) {
        
        vector<vector<int>> res;
        if(root==NULL) return res;

        queue<Node*> q;
        q.push(root);
        while(!q.empty()){
            int n = q.size();
            vector<int> v;
            for(int i=0;i<n;i++){
                Node* node = q.front();
                q.pop();
                v.push_back(node->val);
                for(int j=0;j<node->children.size();j++){
                    if(node->children[j]){
                        q.push(node->children[j]);
                    }
                }
            }
            res.push_back(v);
        }
        return res;
    }
};