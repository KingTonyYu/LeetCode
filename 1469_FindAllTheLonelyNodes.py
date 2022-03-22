# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def getLonelyNodes(self, root: Optional[TreeNode]) -> List[int]:
        self.list = []
        self.helper(root)

        return self.list

    def helper(self, root):
        if root == None:
            return
        self.helper(root.left)
        self.helper(root.right)
        if (root.left == None and root.right != None):
            self.list.append(root.right.val)
        if (root.left != None and root.right == None):
            self.list.append(root.left.val)
