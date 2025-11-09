class Solution:
    def targetIndices(self, nums: List[int], target: int) -> List[int]:
        smaller_count = 0
        freq = 0

        for num in nums:
            if num < target:
                smaller_count += 1
            elif num == target:
                freq += 1

        return list(range(smaller_count, smaller_count + freq))
