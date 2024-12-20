# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def __init__(self):
	    self.diameter = 0

    def depth(self,root) -> int:
        if root==None:
            return 0
        
        left = self.depth(root.left)
        right = self.depth(root.right)
        self.diameter = max(self.diameter, left+right)
        return max(left,right)+1
    
    def diameterOfBinaryTree(self, root: Optional[TreeNode]) -> int:
        if root==None:
            return 0
        
        # left = self.depth(root.left)
        # right = self.depth(root.right)
        # maxm = max(left+right,max(self.diameterOfBinaryTree(root.left),self.diameterOfBinaryTree(root.right)))
        self.depth(root)
        return self.diameter
        