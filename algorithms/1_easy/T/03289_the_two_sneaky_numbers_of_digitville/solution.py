class Solution:
    def getSneakyNumbers(self, nums: List[int]) -> List[int]:
        MAX_NUM = 100
        freqs = [0] * MAX_NUM

        for num in nums:
            freqs[num] += 1

        res = []
        for i in range(MAX_NUM):
            if freqs[i] > 1:
                res.append(i)

        return res
