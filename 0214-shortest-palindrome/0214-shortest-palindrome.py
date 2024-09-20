class Solution(object):
    def shortestPalindrome(self, s):
        reverse = s[::-1]

        for i in range(len(s)):
            if s.startswith(reverse[i:]):
                return reverse[:i] + s      

        return s + reverse
        