class Solution:

    def inorder(self, root, res):
        if not root:
            return

        self.inorder(root.left, res)
        res.append(root.val)
        self.inorder(root.right, res)

    def kthSmallest(self, root: Optional[TreeNode], k: int) -> int:
        res = []

        self.inorder(root, res)

        for i in range(len(res)):
            if i == k - 1:
                return res[i]

        return -1