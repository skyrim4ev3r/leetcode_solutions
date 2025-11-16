from heapq import heappop, heappush

class Solution:
    def kWeakestRows(self, mat: List[List[int]], k: int) -> List[int]:
        heap = []

        for (index, row) in enumerate(mat):
            count = row.count(1)

            if len(heap) < k:
                heappush(heap, (-count, -index))
            else:
                if -heap[0][0] > count:
                    heappush(heap, (-count, -index))
                    heappop(heap)

        heap_len = len(heap)
        res = [0] * heap_len

        for i in range(heap_len - 1, -1, -1):
            res[i] = -(heappop(heap)[1])

        return res
