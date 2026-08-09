class Solution:
    def maxPathSum(self, root: Optional[TreeNode]) -> int:

        self.res = root.val

        def summy(root):
            if not root:
                return 0

            leftsum = summy(root.left)
            rightsum = summy(root.right)

            # path passing through root
            self.res = max(self.res, root.val + max(0, leftsum) + max(0, rightsum))

            # give parent the better side
            return root.val + max(0, leftsum, rightsum)

        summy(root)

        return self.res