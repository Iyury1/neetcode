from typing import Optional

# Definition for a binary tree node.
class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right
        
class Solution:   
    def isSubtree(self, root: Optional[TreeNode], subRoot: Optional[TreeNode]) -> bool:
        if self.compareTrees(root, subRoot):
            return True
        if not root or not subRoot:
            return False
        return (self.isSubtree(root.right, subRoot) or
               self.isSubtree(root.left, subRoot))


    def compareTrees(self, root1: Optional[TreeNode], root2: Optional[TreeNode]) -> bool:
        if not root1 and not root2:
            return True
        if not (root1 and root2):
            return False
        if root1.val != root2.val:
            return False
        return (self.compareTrees(root1.left, root2.left) and
               self.compareTrees(root1.right, root2.right))
