from heapq import heappush, heappop

class Solution:
    def lastStoneWeight(self, stones: List[int]) -> int:
        heap = []

        for stone in stones:
            heappush(heap, -stone)

        while len(heap) > 1:
            x = heappop(heap)
            y = heappop(heap)

            if x != y:
                heappush(heap, x - y)

        return abs(heap.pop()) if heap else 0
