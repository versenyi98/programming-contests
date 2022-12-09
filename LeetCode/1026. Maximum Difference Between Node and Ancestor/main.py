# Definition for a binary tree node.
# class TreeNode(object):
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution(object):
    def maxAncestorDiff(self, root):
        """
        :type root: TreeNode
        :rtype: int
        """
        self.values = []
        self.max_dist = -1
        self.preorder(root)

        return self.max_dist

    def preorder(self, node):
        self.values.append(node.val)
        if node.left is None and node.right is None:
            self.max_dist = max(self.max_dist, abs(max(self.values) - min(self.values)))
        if node.left:
            self.preorder(node.left)
        if node.right:
            self.preorder(node.right)
        self.values.pop(-1)