from heapq import heappop, heappush

class Solution:
    def maxSum(self, grid: List[List[int]], limits: List[int], k: int) -> int:
        if k == 0:
            return 0

        for row in grid:
            row.sort(reverse=True)

        heap = []

        for (i, row) in enumerate(grid):
            for j in range(limits[i]):
                if row[j] == 0 or (len(heap) == k and row[j] <= -1 * heap[0]):
                    break

                heappush(heap, row[j])

                if len(heap) > k:
                    heappop(heap)

        return sum(heap)
