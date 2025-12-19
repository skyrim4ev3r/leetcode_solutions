class Solution:
    def backtrack(
        self,
        nums: List[int],
        res: List[List[int]],
        temp: List[int],
        curr_index: int,
        n: int
    ):
        res.append(temp.copy())

        for  i in range(curr_index, n):
            if i > curr_index and nums[i] == nums[i - 1]:
                continue

            temp.append(nums[i])
            self.backtrack(nums, res, temp, i + 1, n)
            temp.pop()

    def subsetsWithDup(self, nums: List[int]) -> List[List[int]]:
        temp = []
        res = []

        nums.sort()
        self.backtrack(nums, res, temp, 0, len(nums))

        return res
