class Solution:
    def maximumScore(self, nums: List[int], s: str) -> int:
        n: int = len(nums)
        heap: List[int] = []
        total_sum: int = 0

        for i in range(n):
            heappush(heap, -nums[i])

            if s[i] == '1':
                total_sum += (-heappop(heap))

        return total_sum
