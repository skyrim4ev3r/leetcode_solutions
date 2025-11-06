class Solution:
    def countDigits(self, num: int) -> int:
        num_cp = num
        count = 0

        while num_cp > 0:
            dig = num_cp % 10
            num_cp //= 10

            if dig == 0:
                continue

            if num % dig == 0:
                count += 1

        return count
