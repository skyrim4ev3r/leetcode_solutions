class Solution:
    def getLucky(self, s: str, k: int) -> int:
        total_sum = 0

        for ch in s:
            num = ord(ch) - ord('a') + 1
            total_sum += num % 10 + num // 10

        for i in range(1, k):
            tmp = 0
            while total_sum > 0:
                tmp += total_sum % 10
                total_sum //= 10
            total_sum = tmp

        return total_sum
