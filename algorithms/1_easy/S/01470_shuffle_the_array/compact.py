class Solution:
    def shuffle(self, nums: List[int], n: int) -> List[int]:
        return [item for i in range(n) for item in (nums[i], nums[i + n])]
