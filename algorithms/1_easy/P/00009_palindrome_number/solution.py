class Solution:
    def isPalindrome(self, x: int) -> bool:

        if x < 0:
            return False

        reversed_num = 0
        tmp = x

        while tmp > 0:
            reversed_num = reversed_num * 10 + tmp % 10
            tmp //= 10

        return reversed_num == x
