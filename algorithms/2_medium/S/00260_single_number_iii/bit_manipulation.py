class Solution:
    def singleNumber(self, nums: List[int]) -> List[int]:
        nums_xor = 0

        for num in nums:
            nums_xor ^= num

        least_bit_one = nums_xor & (-nums_xor)
        num1 = 0
        num2 = 0

        for num in nums:
            if (least_bit_one & num) == 0:
                num1 ^= num
            else:
                num2 ^= num

        return [num1, num2]
