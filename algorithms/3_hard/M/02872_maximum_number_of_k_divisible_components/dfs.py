class Solution:
    def dfs(self, new_edges, values, is_seen, k, curr):
        val = values[curr]
        is_seen[curr] = True

        for child in new_edges[curr]:
            if not is_seen[child]:
                val += self.dfs(new_edges, values, is_seen, k, child)

        if val % k == 0:
            self.count += 1
            return 0

        return val

    def maxKDivisibleComponents(self, n: int, edges: List[List[int]], values: List[int], k: int) -> int:
        self.count = 0
        new_edges = [[] for _ in range(n)]
        is_seen = [False] * n

        for edge in edges:
            new_edges[edge[0]].append(edge[1])
            new_edges[edge[1]].append(edge[0])

        self.dfs(new_edges, values, is_seen, k, 0)

        return self.count
