class Solution:
    def has_any_zero(self, n):
        while n > 0:
            if n % 10 == 0:
                return True

            n //= 10

        return False

    def getNoZeroIntegers(self, n: int) -> List[int]:
        for i in range(1, n):
            if not self.has_any_zero(i) and not self.has_any_zero(n - i):
                return [i, n - i]

        return []
