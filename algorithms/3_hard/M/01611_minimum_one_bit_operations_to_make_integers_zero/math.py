class Solution:
    def minimumOneBitOperations(self, n: int) -> int:
        res = 0
        curr_index = 0

        while n > 0:
            if n % 2 == 1:
                res = (2 ** (curr_index + 1)) - 1 - res
            n //= 2
            curr_index += 1

        return res
