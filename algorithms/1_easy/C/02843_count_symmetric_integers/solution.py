class Solution:
    def countSymmetricIntegers(self, low: int, high: int) -> int:
        count = 0

        for i in range(low, high + 1):
            temp = i

            digits = []

            while temp > 0:
                digits.append(temp % 10)
                temp //= 10

            if (len(digits) & 1) == 1:
                continue

            half = len(digits) // 2
            left = sum(digits[0 : half])
            right = sum(digits[half:])

            if left == right:
                count += 1

        return count
