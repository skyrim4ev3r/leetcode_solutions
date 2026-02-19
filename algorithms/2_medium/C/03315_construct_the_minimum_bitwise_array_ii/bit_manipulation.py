class Solution:
    def minBitwiseArray(self, nums: List[int]) -> List[int]:
        n = len(nums)
        res = [0] * n

        for i in range(n):
            num = nums[i]

            if num == 2:
                res[i] = -1; # Special case for prime number 2
            else:
                mask = 1
                # Find the lowest bit that is 0
                while (num & mask) != 0:
                    mask = mask << 1
                mask = mask >> 1; # Move back to the last bit that was 1
                res[i] = (num ^ mask) # Toggle that bit

        return res
