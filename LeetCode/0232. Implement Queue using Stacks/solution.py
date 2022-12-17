class MyQueue(object):

    def __init__(self):
        self.stack = []

    def push(self, x):
        """
        :type x: int
        :rtype: None
        """
        self.stack.append(x)

    def pop(self):
        """
        :rtype: int
        """
        other_stack = []
        while self.stack:
            other_stack.append(self.stack.pop(-1))
        value = other_stack.pop(-1)
        while other_stack:
            self.stack.append(other_stack.pop(-1))
        return value

    def peek(self):
        """
        :rtype: int
        """
        other_stack = []
        while self.stack:
            other_stack.append(self.stack.pop(-1))
        value = other_stack[-1]
        while other_stack:
            self.stack.append(other_stack.pop(-1))
        return value

    def empty(self):
        """
        :rtype: bool
        """
        return not self.stack

# Your MyQueue object will be instantiated and called as such:
# obj = MyQueue()
# obj.push(x)
# param_2 = obj.pop()
# param_3 = obj.peek()
# param_4 = obj.empty()