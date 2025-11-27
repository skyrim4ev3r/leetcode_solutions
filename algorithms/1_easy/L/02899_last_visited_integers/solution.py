class Solution:
    def lastVisitedIntegers(self, nums: List[int]) -> List[int]:
        seen = []
        consecutive_negative_ones = 0
        res = []

        for num in nums:
            if num == -1:
                consecutive_negative_ones += 1

                if consecutive_negative_ones > len(seen):
                    res.append(-1)
                else:
                    res.append(seen[len(seen) - consecutive_negative_ones])
            else:
                seen.append(num)
                consecutive_negative_ones = 0

        return res
