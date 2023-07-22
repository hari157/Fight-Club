# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
from queue import LifoQueue
class Solution:
    def preorderTraversal(self, root: Optional[TreeNode]) -> List[int]:
        sp=LifoQueue()
        if root==None:
                return
        sp.put(root)
        List=[]
        while(sp.empty()!=True):
                root1=sp.get()
                List.append(root1.val)
                if(root1.left!=None and root1.right!=None):
                        sp.put(root1.right)
                        sp.put(root1.left)
                elif(root1.left!=None):
                        sp.put(root1.left)
                elif(root1.right!=None):
                        sp.put(root1.right)
        return List

