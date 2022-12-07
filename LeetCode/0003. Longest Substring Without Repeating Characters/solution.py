class Solution(object):
    def lengthOfLongestSubstring(self, s):
        """
        :type s: str
        :rtype: int
        """
        current = []
        current_len = 0

        for element in s:
            if element in current:
                index = current.index(element)
                current = current[index + 1:]
            current += [element]
            current_len = max(current_len, len(current))

        return current_len