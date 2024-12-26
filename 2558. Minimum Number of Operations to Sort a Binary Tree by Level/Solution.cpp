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
    int minOperations(vector<int> arr){
        vector<int> temp(arr.begin(),arr.end());
        sort(temp.begin(),temp.end());
        unordered_map<int,int> mp;
        for(int i=0;i<arr.size();i++){
            mp[arr[i]] = i;
        }
        int cnt=0;
        for(int i=0;i<arr.size();i++){
            if(arr[i]!=temp[i]){
                cout<<arr[i]<<"-"<<temp[i]<<"-"<<mp[temp[i]]<<endl;
                swap(arr[i],arr[mp[temp[i]]]);
                int tempIdx = mp[temp[i]];
                mp[arr[i]]=i;
                mp[arr[tempIdx]] = tempIdx;

                cnt++;
            }
        }
        return cnt;
    }
    int minimumOperations(TreeNode* root) {

       queue<TreeNode*> q;
       q.push(root);
       int minCount=0;
       while(!q.empty()){
            int size = q.size();
            vector<int> v;
            for(int i=0;i<size;i++){
                TreeNode* node = q.front();
                q.pop();
                if(node->left){
                    v.push_back(node->left->val);
                    q.push(node->left);
                }
                if(node->right){
                    v.push_back(node->right->val);
                    q.push(node->right);
                }
            }

            if(v.size()>1){
                minCount+=minOperations(v);
            }
       } 
       return minCount;
    }
};