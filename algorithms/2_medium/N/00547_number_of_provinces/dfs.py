class Solution:
    def dfs(self, is_connected, is_seen, n, row):
        if is_seen[row]:
            return

        is_seen[row] = True
        for i in range(n):
            if is_connected[row][i] == 1:
                self.dfs(is_connected, is_seen, n, i)

    def findCircleNum(self, is_connected: List[List[int]]) -> int:
        n = len(is_connected)
        is_seen = [False] * n
        count = 0

        for i in range(n):
            if not is_seen[i]:
                count += 1
                self.dfs(is_connected, is_seen, n, i)

        return count
