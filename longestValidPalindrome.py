class Solution(object):
    def expand(self, l, r, s):
        while l >= 0 and r < len(s):
            if s[l] == s[r]:
                l -= 1
                r += 1
            else:
                break

        return l, r

    def longestPalindrome(self, s):
        """
        :type s: str
        :rtype: str
        """
        if not s:
            return ""

        start, end = 0, 0

        for i in range(len(s)):
            # For even numbers
            l1, r1 = self.expand(i, i, s)

            # For odd numbers
            l2, r2 = self.expand(i, i + 1, s)

            if r1 - l1 - 1 > end - start:
                start, end = l1 + 1, r1 - 1
            if r2 - l2 - 1 > end - start:
                start, end = l2 + 1, r2 - 1

        return s[start : end + 1]

        