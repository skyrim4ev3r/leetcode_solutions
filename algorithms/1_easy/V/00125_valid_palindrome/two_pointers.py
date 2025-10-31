class Solution:
    def isPalindrome(self, s: str) -> bool:
        def is_valid(ch):
            return (ord('A') <= ord(ch) and ord(ch) <= ord('Z')) or \
                (ord('a') <= ord(ch) and ord(ch) <= ord('z')) or \
                (ord('0') <= ord(ch) and ord(ch) <= ord('9'))

        right = len(s) - 1
        left = 0

        while left < right:
            if not is_valid(s[left]):
                left += 1
            elif not is_valid(s[right]):
                right -= 1
            else:
                if s[left].lower() != s[right].lower():
                    return False

                right -= 1
                left += 1

        return True
