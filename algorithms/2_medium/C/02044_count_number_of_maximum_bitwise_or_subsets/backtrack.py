class Solution:
    def subsets_backtrack(self, nums, curr_or, start_index):
        if curr_or == self.max_or:
            self.count += 2 ** (len(nums) - start_index);
            return

        for i in range(start_index, len(nums)):
            self.subsets_backtrack(nums, curr_or | nums[i], i + 1)

    def countMaxOrSubsets(self, nums: List[int]) -> int:
        self.max_or = 0
        for num in nums:
            self.max_or |= num
        self.count = 0
        self.subsets_backtrack(nums, 0, 0)

        return self.count
