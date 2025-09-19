from typing import Optional

# Definition for a binary tree node.
class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right

class Solution:
    def diameterOfBinaryTree(self, root: Optional[TreeNode]) -> int:

        self.max_diameter = 0
        self.checkDiameter(root)
        return(self.max_diameter)

    def checkDiameter(self, root: Optional[TreeNode]):
        if not root:
            return 0
        left_height = self.checkDiameter(root.left)
        right_height = self.checkDiameter(root.right)
        if left_height + right_height > self.max_diameter:
            self.max_diameter = left_height + right_height
        return max(left_height, right_height) + 1