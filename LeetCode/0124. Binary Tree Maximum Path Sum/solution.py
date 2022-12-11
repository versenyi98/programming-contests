# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def maxPathSum(self, root: Optional[TreeNode]) -> int:
        self.candidates = []
        self.traverse(root)
        return max(self.candidates) if self.candidates else 0

    def traverse(self, node):
        if not node:
            return 0

        left = self.traverse(node.left)
        right = self.traverse(node.right)

        left_self = left + node.val
        right_self = right + node.val

        left_right_self = left + right + node.val
        ret_val = max(left_self, right_self, node.val)

        self.candidates.extend([ret_val, left_right_self])

        return ret_val
