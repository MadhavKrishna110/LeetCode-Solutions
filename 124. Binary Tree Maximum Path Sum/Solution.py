# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def __init__(self):
        self.maxSum=-1e9

    def depth(self,root) -> int:
        if root==None:
            return -1e9
        left = self.depth(root.left)
        right = self.depth(root.right)
        self.maxSum = max(self.maxSum,root.val+left+right)
        branchSum = max(root.val,max(root.val+left,root.val+right))
        self.maxSum = max(self.maxSum, branchSum)
        self.maxSum=max(self.maxSum,max(left,right))
        
        return branchSum

    def maxPathSum(self, root: Optional[TreeNode]) -> int:
        if root==None:
            return -1e9
        one = self.depth(root)
        # left = self.maxPathSum(root.left)
        # right = self.maxPathSum(root.right)

        # maxSum =  max(maxSum,max(left,right))
        # maxSum = max(maxSum,one)
        return self.maxSum

        
        