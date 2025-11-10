class Solution:
    def is_beautifull(self, num):
        freqs = [0] * 10

        while num > 0:
            freqs[num % 10] += 1
            num //= 10

        for i in range(10):
            if freqs[i] != 0 and freqs[i] != i:
                return False

        return True

    def nextBeautifulNumber(self, n: int) -> int:
        next_num = n + 1

        while True:
            if self.is_beautifull(next_num):
                return next_num

            next_num += 1
