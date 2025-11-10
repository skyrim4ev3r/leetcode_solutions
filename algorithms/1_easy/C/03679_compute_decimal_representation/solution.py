class Solution:
    def decimalRepresentation(self, n: int) -> List[int]:
        p = 1
        while n // p >= 10:
            p *= 10

        res = []

        while p > 0:
            temp = ((n // p) % 10) * p

            if temp != 0:
                res.append(temp)

            p //= 10

        return res
