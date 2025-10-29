class Solution:
    def is_palindrome(self, s, left, right, penalty) -> bool:
        while left < right:
            if s[left] != s[right]:
                if penalty > 0:
                    return self.is_palindrome(s, left + 1, right, penalty - 1) or \
                           self.is_palindrome(s, left, right - 1, penalty - 1)
                else:
                    return False

            left += 1
            right -= 1

        return True

    def validPalindrome(self, s: str) -> bool:
        return self.is_palindrome(s, 0, len(s) - 1, 1)
