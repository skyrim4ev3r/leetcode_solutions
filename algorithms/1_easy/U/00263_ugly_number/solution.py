class Solution:
    def isUgly(self, n: int) -> bool:

        if n <= 0:
            return False

        arr = [2, 3, 5]

        for num in arr:
            while n != 0 and n % num == 0:
                n //= num

        return n == 1
