INT_MAX = sys.maxsize

class Solution:
    def networkDelayTime(self, times: List[List[int]], n: int, k: int) -> int:
        dist = [INT_MAX] * (n + 1)
        dist[k] = 0

        for _ in range(n):
            is_updated = False

            for t in times:
                u, v, w = t

                if dist[u] != INT_MAX and dist[u] + w < dist[v]:
                    dist[v] = dist[u] + w
                    is_updated = True

            if not is_updated:
                break

        max_dist = max(dist[1:])

        return -1 if max_dist == INT_MAX else max_dist
