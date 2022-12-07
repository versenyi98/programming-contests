class Solution(object):
    def findMedianSortedArrays(self, nums1, nums2):
        """
        :type nums1: List[int]
        :type nums2: List[int]
        :rtype: float
        """

        idx1 = 0
        idx2 = 0

        arr = []

        length = len(nums1) + len(nums2)

        even = length % 2 == 0
        goal = length // 2
        other = 0

        inf = (nums1[-1] if nums1 else 0) + (nums2[-1] if nums2 else 0)

        while True:
            toomuch1 = idx1 == len(nums1)
            toomuch2 = idx2 == len(nums2)

            num1 = nums1[idx1] if not toomuch1 else inf
            num2 = nums2[idx2] if not toomuch2 else inf

            if idx1 + idx2 == goal:
                if even:
                    return (min(num1, num2) + other) / 2.0
                else:
                    return min(num1, num2)
            other = min(num1, num2)

            if num1 < num2:
                idx1 += 1
            else:
                idx2 += 1