class Solution:
    def totalWaviness(self, num1: int, num2: int) -> int:
        count = 0

        for i in range(num1, num2 + 1):
            temp = i
            digits = []

            while temp > 0:
                digits.append(temp % 10)
                temp //= 10

            n = len(digits)
            for i in range(1, n - 1):
                if (
                    (digits[i] > digits[i - 1] and digits[i] > digits[i + 1]) or
                    (digits[i] < digits[i - 1] and digits[i] < digits[i + 1])
                ):
                    count += 1

        return count
