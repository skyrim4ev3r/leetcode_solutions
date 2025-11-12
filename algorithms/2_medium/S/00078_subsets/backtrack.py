class Solution:
    def subsets_recursive(self, nums, start_index):
        self.res.append(self.curr_list[:])

        for i in range(start_index, len(nums)):
            self.curr_list.append(nums[i])
            self.subsets_recursive(nums, i + 1)
            self.curr_list.pop()

    def subsets(self, nums: List[int]) -> List[List[int]]:
        self.res = []
        self.curr_list = []

        self.subsets_recursive(nums, 0)

        return self.res
