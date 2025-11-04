class Solution:
    def sumOfTheDigitsOfHarshadNumber(self, x: int) -> int:
        tmp = x
        dig_sum = 0

        while tmp > 0:
            dig_sum += tmp % 10
            tmp //= 10

        if x % dig_sum != 0:
            return -1

        return dig_sum
