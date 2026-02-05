class Solution:
    def constructTransformedArray(self, nums: List[int]) -> List[int]:
        n = len(nums)
        res = [0] * n

        for i in range(n):
            steps = nums[i] % n
            target_index = (i + steps + n) % n
            res[i] = nums[target_index]

        return res
