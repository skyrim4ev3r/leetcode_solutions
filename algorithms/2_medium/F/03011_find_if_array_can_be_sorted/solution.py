class Solution:
    def canSortArray(self, nums: List[int]) -> bool:
        curr_max = -sys.maxsize - 1
        prev_max = -sys.maxsize - 1

        for num in nums:
            if bin(curr_max).count('1') != bin(num).count('1'):
                prev_max = curr_max
                curr_max = num
            else:
                curr_max = max(curr_max, num)

            if num < prev_max:
                return False

        return True
