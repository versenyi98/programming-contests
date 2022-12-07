# Definition for singly-linked list.
# class ListNode(object):
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution(object):
    def addTwoNumbers(self, l1, l2):
        """
        :type l1: ListNode
        :type l2: ListNode
        :rtype: ListNode
        """
        value = l1.val + l2.val
        head = None
        prev = head
        remainder = 0

        while l1 or l2 or remainder:
            lval = l1.val if l1 else 0
            rval = l2.val if l2 else 0
            value = remainder + rval + lval
            node = ListNode(value % 10)
            remainder = value // 10
            if not head:
                head = node
            if prev:
                prev.next = node
            prev = node

            if l1:
                l1 = l1.next
            if l2:
                l2 = l2.next

        return head