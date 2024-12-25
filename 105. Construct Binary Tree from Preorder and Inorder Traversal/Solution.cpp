// /**
//  * Definition for a binary tree node.
//  * struct TreeNode {
//  *     int val;
//  *     TreeNode *left;
//  *     TreeNode *right;
//  *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
//  *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
//  *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
//  * };
//  */
// class Solution {
// public:
//     TreeNode* buildTree(vector<int>& preorder,int preStart, int preEnd,vector<int>& inorder,int inStart,int inEnd,map<int,int> mp){
//         if(preStart>preEnd || inStart>inEnd){
//             return NULL;
//         }

//         TreeNode* root = new TreeNode(preorder[preStart]);
//         int inRoot = mp[root->val];
//         int numsTotal = inRoot-inStart;
//         root->left = buildTree(preorder,preStart+1,preStart+numsTotal,inorder,inStart,inRoot-1,mp);
//         root->right = buildTree(preorder,preStart+numsTotal+1,preEnd,inorder,inRoot+1,inEnd,mp);

//         return root;
//     }

//     TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
//         map<int,int> mp;
//         int n = preorder.size();
//         for(int i=0;i<inorder.size();i++){
//             mp[inorder[i]]=i;
//         }

//         return buildTree(preorder,0,n-1,inorder,0,n-1,mp);
//     }
// };

class Solution {
public:
TreeNode* constructTree(vector < int > & preorder, int preStart, int preEnd, vector 
 < int > & inorder, int inStart, int inEnd, map < int, int > & mp) {
  if (preStart > preEnd || inStart > inEnd) return NULL;

  TreeNode* root = new TreeNode(preorder[preStart]);
  int elem = mp[root -> val];
  int nElem = elem - inStart;

  root -> left = constructTree(preorder, preStart + 1, preStart + nElem, inorder,
  inStart, elem - 1, mp);
  root -> right = constructTree(preorder, preStart + nElem + 1, preEnd, inorder, 
  elem + 1, inEnd, mp);

  return root;
}

TreeNode* buildTree(vector < int > & preorder, vector < int > & inorder) {
  int preStart = 0, preEnd = preorder.size() - 1;
  int inStart = 0, inEnd = inorder.size() - 1;

  map < int, int > mp;
  for (int i = inStart; i <= inEnd; i++) {
    mp[inorder[i]] = i;
  }

  return constructTree(preorder, preStart, preEnd, inorder, inStart, inEnd, mp);
}
};