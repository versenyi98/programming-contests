# Definition for a binary tree node.
# class TreeNode(object):
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution(object):
    def leafSimilar(self, root1, root2):
        """
        :type root1: TreeNode
        :type root2: TreeNode
        :rtype: bool
        """
        values1 = [value for value in self.get_inorder(root1)]
        values2 = [value for value in self.get_inorder(root2)]

        return values1 == values2

    def get_inorder(self, root):
        if root.left:
            for val in self.get_inorder(root.left):
                yield val
        if not root.left and not root.right:
            yield root.val
        if root.right:
            for val in self.get_inorder(root.right):
                yield val