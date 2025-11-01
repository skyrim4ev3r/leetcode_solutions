from heapq import heappop, heappush
INT_MAX = sys.maxsize

class Solution:
    def totalCost(self, costs: List[int], k: int, candidates: int) -> int:

        costs_len = len(costs)

        left_heap = []
        right_heap = []

        left_index = 0
        right_index = costs_len - 1
        res = 0

        for _ in range(k):
            while left_index <= right_index and len(left_heap) < candidates:
                heappush(left_heap, costs[left_index])
                left_index += 1

            while left_index <= right_index and len(right_heap) < candidates:
                heappush(right_heap, costs[right_index])
                right_index -= 1

            cost_left = INT_MAX if not left_heap else left_heap[0]
            cost_right = INT_MAX if not right_heap else right_heap[0]

            if cost_left <= cost_right:
                res += cost_left
                heappop(left_heap)

            else:
                res += cost_right
                heappop(right_heap)

        return res
