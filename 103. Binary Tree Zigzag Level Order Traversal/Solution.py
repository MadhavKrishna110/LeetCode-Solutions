from queue import Queue
# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def zigzagLevelOrder(self, root: Optional[TreeNode]) -> List[List[int]]:
        if root==None:
            return []
        
        q = Queue()
        q.put(root)
        q.put(None)
        res = []
        level = []
        numLevel=1
        while not q.empty():
            item = q.get()
            if item!=None:
                level.append(item.val)
                if item.left!=None:
                    q.put(item.left)
                if item.right!=None:
                    q.put(item.right)
            else:
                if numLevel%2==0:
                    level.reverse()
                res.append(level)
                level=[]
                if not q.empty():
                    q.put(None)
                numLevel+=1
        
        return res
        