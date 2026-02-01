class Solution:
    def clumsy(self, n: int) -> int:
        is_first = True
        res = 0

        while n > 0:
            curr = n
            n -= 1

            if n > 0:
                curr *= n
                n -= 1

            if n > 0:
                curr //= n
                n -= 1

            if is_first:
                res += curr
                is_first = False
            else:
                res -= curr

            if n > 0:
                res += n
                n -= 1

        return res
