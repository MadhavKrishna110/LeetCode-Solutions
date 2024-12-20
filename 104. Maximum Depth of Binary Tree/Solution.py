# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def depth(self,root):
        if root == None:
            return 0
        
        left = self.depth(root.left)
        right = self.depth(root.right)
        return max(left,right)+1

    def maxDepth(self, root: Optional[TreeNode]) -> int:
        if root==None:
            return 0
        
        return self.depth(root)
        