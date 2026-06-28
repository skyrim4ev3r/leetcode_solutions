class Solution:
    def maximumElementAfterDecrementingAndRearranging(self, arr: List[int]) -> int:
        arr.sort()
        curr = 0

        for num in arr:
            if num > curr:
                curr += 1

        return curr
