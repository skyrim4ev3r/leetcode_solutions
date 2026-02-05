class Solution:
    def minSpeedOnTime(self, dist: List[int], hour: float) -> int:
        if ceil(hour) <= len(dist) - 1:
            return -1

        high = 10_000_000
        low = 1
        n = len(dist)

        while low <= high:
            mid = low + (high - low) // 2
            curr_cost = sum([ceil(d/mid) for d in dist[:-1]])
            curr_cost += dist[-1] / mid

            if curr_cost <= hour:
                high = mid - 1
            else:
                low = mid + 1

        return low
