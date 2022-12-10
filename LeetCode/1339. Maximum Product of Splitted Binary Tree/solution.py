# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def maxProduct(self, root: Optional[TreeNode]) -> int:
        self.values = []
        root_sum = self.get_sum_of_node(root)

        maximum = 0
        for val in self.values:
            product = val * (root_sum - val)
            if product > maximum:
                maximum = product
        return maximum % (pow(10, 9) + 7)

    def get_sum_of_node(self, node):
        if not node:
            return 0

        self_sum = self.get_sum_of_node(node.left) + \
            self.get_sum_of_node(node.right) + node.val
        self.values.append(self_sum)

        return self_sum
