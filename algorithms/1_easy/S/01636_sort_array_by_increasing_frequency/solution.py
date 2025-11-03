class Solution:
    def frequencySort(self, nums: List[int]) -> List[int]:

        res =[]
        arr = sorted(Counter(nums).items(), key=lambda item: (item[1], -item[0]))

        for (num, count) in arr:
            res += [num] * count

        return res
