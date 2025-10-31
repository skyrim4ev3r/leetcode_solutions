class Solution:
    def majorityElement(self, nums: List[int]) -> int:
        majority_candidate = 0
        count = 0

        for num in nums:
            if count == 0:
                majority_candidate = num
                count = 1
            elif majority_candidate == num:
                count += 1
            else:
                count -= 1

        return majority_candidate
