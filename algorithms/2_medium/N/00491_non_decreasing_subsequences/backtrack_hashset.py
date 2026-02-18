class Solution:
    def backtrack(self, nums: List[int], res: List[List[int]], temp: List[int], curr_index: int, n: int):
        visited = set()
        for i in range(curr_index, n):
            if nums[i] in visited:
                continue

            visited.add(nums[i])

            if len(temp) == 0 or nums[i] >= temp[-1]:
                temp.append(nums[i])
                if len(temp) > 1:
                    res.append(temp.copy())
                self.backtrack(nums, res, temp, i + 1, n)
                temp.pop()

    def findSubsequences(self, nums: List[int]) -> List[List[int]]:
        n = len(nums)
        temp = []
        res = []

        self.backtrack(nums, res, temp, 0, n)

        return res
