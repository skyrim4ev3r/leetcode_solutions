class Solution:
    def rev_digits(self, num: int) -> i32:
        rev = 0
        while num > 0:
            rev = rev * 10 + num % 10;
            num //= 10
        return rev

    def minMirrorPairDistance(self, nums: List[int]) -> int:
        nums.reverse()
        seen = {}
        min_abs_diff = sys.maxsize

        for (i, num) in enumerate(nums):
            rev = self.rev_digits(num)
            val = seen.get(rev)
            if val != None:
                min_abs_diff = min(min_abs_diff, i - val)
            seen[num] = i

        if min_abs_diff == sys.maxsize:
            return -1
        return min_abs_diff
