# Definition for a binary tree node.
# class TreeNode(object):
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution(object):
    def rangeSumBST(self, root, low, high):
        """
        :type root: TreeNode
        :type low: int
        :type high: int
        :rtype: int
        """
        return self.rangeSumBSTRec(root, low, high)

    def rangeSumBSTRec(self, node, low, high):
        result = 0
        if node:
            if low <= node.val <= high:
                result = node.val
                result += self.rangeSumBSTRec(node.left, low, high)
                result += self.rangeSumBSTRec(node.right, low, high)
            elif low >= node.val:
                result += self.rangeSumBSTRec(node.right, low, high)
            elif high <= node.val:
                result += self.rangeSumBSTRec(node.left, low, high)
        return result