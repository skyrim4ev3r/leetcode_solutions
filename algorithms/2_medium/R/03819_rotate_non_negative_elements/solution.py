class Solution:
    def rotateElements(self, nums: List[int], k: int) -> List[int]:
        nums_len = len(nums)
        positive_vals = []

        for num in nums:
            if num >= 0:
                positive_vals.append(num)

        positive_len = len(positive_vals)

        if positive_len == 0:
            return nums

        k %= positive_len
        positive_vals = positive_vals[k:] + positive_vals[:k]

        positive_index = 0
        for nums_index in range(nums_len):
            if nums[nums_index] >= 0:
                nums[nums_index] = positive_vals[positive_index]
                positive_index += 1

        return nums
