class Solution:
    def findScore(self, nums: List[int]) -> int:
        n = len(nums)
        res = 0
        heap = []

        for (i, num) in enumerate(nums):
            heappush(heap, (num, i))

        while heap:
            index = heappop(heap)[1]

            if nums[index] < 0:
                continue

            res += nums[index]
            nums[index] = -1

            if index > 0:
                nums[index - 1] = -1

            if index + 1 < n:
                nums[index + 1] = -1

        return res
