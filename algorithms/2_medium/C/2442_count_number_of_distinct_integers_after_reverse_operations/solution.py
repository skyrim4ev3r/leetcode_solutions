class Solution:
    def countDistinctIntegers(self, nums: List[int]) -> int:
        nums_set = set()
        for num in nums:
            nums_set.add(num)
            rev_num = 0
            while num > 0:
                rev_num *= 10
                rev_num += num % 10
                num //= 10
            nums_set.add(rev_num)

        return len(nums_set)
