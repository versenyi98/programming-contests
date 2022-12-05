class Solution(object):
    def middleNode(self, head):
        """
        :type head: ListNode
        :rtype: ListNode
        """

        list_of_nodes = [head]
        while head.next is not None:
            head = head.next
            list_of_nodes.append(head)
        return list_of_nodes[len(list_of_nodes) // 2]