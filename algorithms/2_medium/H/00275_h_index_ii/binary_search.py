class Solution:
    def hIndex(self, citations: List[int]) -> int:
        n = len(citations)
        left = 0
        right = n - 1
        res = 0

        while left <= right:
            mid = left + (right - left) // 2
            least_valid = n - mid

            if citations[mid] >= least_valid:
                res = least_valid
                right = mid - 1
            else:
                left = mid + 1

        return res
