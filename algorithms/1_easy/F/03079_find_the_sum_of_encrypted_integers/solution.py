class Solution:
    def sumOfEncryptedInt(self, nums: List[int]) -> int:
        final_res = 0

        for num in nums:
            dig_count = 0
            max_dig = 0

            while num > 0:
                curr_dig = num % 10
                num //= 10

                max_dig = max(max_dig, curr_dig)
                dig_count += 1

            curr_res = 0
            for i in range(dig_count):
                curr_res *= 10
                curr_res += max_dig

            final_res += curr_res

        return final_res
