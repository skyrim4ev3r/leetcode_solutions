class Solution:
    def checkDivisibility(self, n: int) -> bool:
        temp, d_sum, d_mul = n, 0, 1

        while temp > 0 :
            digit = temp % 10
            d_sum += digit
            d_mul *= digit
            temp //= 10

        return n % (d_sum + d_mul) == 0
