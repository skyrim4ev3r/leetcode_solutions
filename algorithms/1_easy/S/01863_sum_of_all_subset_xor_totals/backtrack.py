class Solution:
    def backtrack(self, start, nums, parent_xor):
        total_sum = 0
        for i in range(start, len(nums)):
            curr_xor = parent_xor ^ nums[i]
            total_sum += curr_xor
            total_sum += self.backtrack(i + 1, nums, curr_xor)

        return total_sum

    def subsetXORSum(self, nums: List[int]) -> int:
        return self.backtrack(0, nums, 0);
