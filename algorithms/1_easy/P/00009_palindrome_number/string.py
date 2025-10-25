class Solution_1:
    def isPalindrome(self, x: int) -> bool:
        return str(x) == str(x)[::-1]

