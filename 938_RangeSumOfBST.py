# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def __init__(self):
        self.sum = 0

    def rangeSumBST(self, root: Optional[TreeNode], low: int, high: int) -> int:
        self.low = low
        self.high = high
        self.helper(root)
        return self.sum

    def helper(self, root):
        if root == None:
            return

        self.helper(root.left)
        if root.val >= self.low and root.val <= self.high:
            self.sum += root.val
        self.helper(root.right)
