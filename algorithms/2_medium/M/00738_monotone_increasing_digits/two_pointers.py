class Solution:
    def get_digits(self, n: int) -> List[int]:
        digits = []

        while n > 0:
            digits.append(n % 10)
            n //= 10

        digits.reverse()

        return digits

    def monotoneIncreasingDigits(self, n: int) -> int:
        if n < 10:
            return n

        digits = self.get_digits(n)
        dig_len = len(digits)
        res = 0
        left = 0
        right = 0

        while right < dig_len:
            if digits[right] == digits[left]:
                right += 1
            elif digits[right] > digits[left]:
                while left < right:
                    res *= 10
                    res += digits[left]
                    left += 1
            else:
                res *= 10
                res += digits[left] - 1
                left += 1

                while left < dig_len:
                    res *= 10
                    res += 9
                    left += 1

                return res

        # If 'right' reach end, then it means n has monotone increasing digits
        # So simply returning n is enough
        return n
