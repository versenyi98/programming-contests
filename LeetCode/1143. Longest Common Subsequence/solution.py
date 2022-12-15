class Solution(object):
    def longestCommonSubsequence(self, text1, text2):
        """
        :type text1: str
        :type text2: str
        :rtype: int
        """
        dp = [0] * (len(text2) + 1)

        for i in range(len(text1)):
            dp_new = [0] * (len(text2) + 1)
            for j in range(len(text2)):
                ch1 = text1[i]
                ch2 = text2[j]

                dp_new[j + 1] = max(dp[j + 1], dp_new[j], dp[j])
                if ch1 == ch2:
                    dp_new[j + 1] = max(dp_new[j + 1], dp[j] + 1)
            dp = dp_new

        return dp[-1]