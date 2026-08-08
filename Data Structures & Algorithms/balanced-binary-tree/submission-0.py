# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right

class Solution:
    def height(self,root):
        if not root:
            return True
        lefth=self.height(root.left)
        righth=self.height(root.right)
        return 1+max(lefth,righth)
    def isBalanced(self, root: Optional[TreeNode]) -> bool:
        if not root:
            return True
        leftht=Solution.height(self,root.left)
        right=Solution.height(self,root.right)
        if abs(leftht-right)>1:
            return False
        return self.isBalanced(root.left)and self.isBalanced(root.right)
        