class Solution:
    def countEven(self, num: int) -> int:
        count = 0

        for i in range(1, num + 1):
            temp = i
            dig_sum = 0

            while temp > 0:
                dig_sum += temp % 10
                temp //= 10

            if (dig_sum & 1) == 0:
                count += 1

        return count
