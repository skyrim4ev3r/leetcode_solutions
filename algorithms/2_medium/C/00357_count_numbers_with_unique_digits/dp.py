class Solution:
    def countNumbersWithUniqueDigits(self, n: int) -> int:
        count = 1; # for n = 0
        ways = 9

        for i in range(1, n + 1):
            count += ways
            ways *= max(0, 10 - i)

        return count
