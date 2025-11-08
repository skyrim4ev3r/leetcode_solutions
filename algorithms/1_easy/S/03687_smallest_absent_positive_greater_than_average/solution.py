class Solution:
    def smallestAbsent(self, nums: List[int]) -> int:
        sum_nums = sum(nums)
        avg = sum_nums // len(nums)

        num_set = set()
        for  num in nums:
            if num > avg and num > 0:
                num_set.add(num)
        res = max(1, avg + 1)
        while res in num_set:
            res += 1

        return res
