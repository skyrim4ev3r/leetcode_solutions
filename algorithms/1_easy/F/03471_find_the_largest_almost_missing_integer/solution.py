class Solution:
    def largestInteger(self, nums: List[int], k: int) -> int:
        n = len(nums)

        if k >= n:
            return max(nums)

        if 1 < k:
            freq_first = nums.count(nums[0])
            freq_last = nums.count(nums[n - 1])

            if freq_first == 1 and freq_last == 1:
                return max(nums[0], nums[n - 1])
            elif freq_first == 1:
                return nums[0]
            elif freq_last == 1:
                return nums[n - 1]
            else:
                return -1

        freqs = defaultdict(int)

        for num in nums:
           freqs[num] += 1

        res = -sys.maxsize
        has_valid_ans = False

        for num, freq in freqs.items():
            if freq == 1:
                res = max(res, num)
                has_valid_ans = True

        if not has_valid_ans:
            return -1

        return res
