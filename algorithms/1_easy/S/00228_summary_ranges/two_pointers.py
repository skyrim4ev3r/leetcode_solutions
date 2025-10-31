class Solution:
    def summaryRanges(self, nums: List[int]) -> List[str]:
        nums_len = len(nums)

        res = []

        # This 'if' is optional; the code logic can handle len of 0. 
        # It's just for clarity and early exit.
        if nums_len == 0:
            return res

        left = 0
        right = 1

        while right <= nums_len:
            while right < nums_len and nums[right - 1] + 1 == nums[right]:
                right += 1

            if left + 1 == right:
                res.append(str(nums[left]))
            else:
                res.append(str(nums[left]) + "->" + str(nums[right - 1]))

            left = right
            right += 1

        return res
