class Solution:
    def subtractProductAndSum(self, n: int) -> int:
        total_sum = 0
        total_mul = 1
        while n > 0:
            tmp = n % 10
            total_mul *= tmp
            total_sum += tmp
            n //= 10

        return total_mul - total_sum
