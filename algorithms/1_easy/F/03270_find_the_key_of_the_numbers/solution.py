class Solution:
    def generateKey(self, num1: int, num2: int, num3: int) -> int:
        p = 1
        res = 0

        while p <= num1 and p <= num2 and p <= num3:
            p *= 10
        p //= 10

        while p > 0:
            curr_min_dig = 9
            curr_min_dig = min(curr_min_dig, (num1 // p) % 10)
            curr_min_dig = min(curr_min_dig, (num2 // p) % 10)
            curr_min_dig = min(curr_min_dig, (num3 // p) % 10)

            p //= 10
            res *= 10
            res += curr_min_dig

        return res
