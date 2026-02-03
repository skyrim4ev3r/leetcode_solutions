class Solution:
    def calc_subarray_score(
        self,
        nums: List[int],
        start: int,
        end: int,
        negative_count: int,
    ) -> int:
        if (negative_count & 1) == 0:
            return (end - start)

        left = start
        right = end - 1

        while nums[left] > 0:
            left += 1

        while nums[right] > 0:
            right -= 1

        max_width = max(right - start, end - 1 - left)

        return max_width

    def getMaxLen(self, nums: List[int]) -> int:
        n = len(nums)
        negative_count = 0
        max_score = 0
        left = 0
        right = 0

        for num in nums:
            if num < 0:
                negative_count += 1

            if num == 0:
                curr_score = self.calc_subarray_score(nums, left, right, negative_count)

                max_score = max(max_score, curr_score)
                left = right + 1
                negative_count = 0

            right += 1

        curr_score = self.calc_subarray_score(nums, left, right, negative_count)
        max_score = max(max_score, curr_score)

        return max_score
