# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    def oddEvenList(self, head: Optional[ListNode]) -> Optional[ListNode]:
        last_odd = None
        last_even = None
        first_even = None


        odd = True
        node = head
        while node is not None:
            if odd:
                if last_odd is not None:
                    last_odd.next = node
                last_odd = node
            else:
                if first_even is None:
                    first_even = node
                if last_even is not None:
                    last_even.next = node
                last_even = node
            odd = not odd
            node = node.next

            if last_even:
                last_even.next = None
            if last_odd:
                last_odd.next = None

        if last_odd:
            last_odd.next = first_even

        return head