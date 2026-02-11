class Solution:
    def maxChunksToSorted(self, arr: List[int]) -> int:
        n = len(arr)
        curr_best = 0
        count = 0

        for i in range(n):
            curr_best = max(curr_best, arr[i])

            if i == curr_best:
                count += 1

        return count
