class Solution:
    def scoreDifference(self, nums: List[int]) -> int:
        points = [0] * 2
        curr_player = 0

        for (i, num) in enumerate(nums):
            if i % 6 == 5:
                curr_player = (curr_player + 1) % 2

            if (nums[i] & 1) == 1:
                curr_player = (curr_player + 1) % 2

            points[curr_player] += nums[i]

        return points[0] - points[1]
