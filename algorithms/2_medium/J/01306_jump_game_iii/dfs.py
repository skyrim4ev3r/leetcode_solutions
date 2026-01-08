class Solution:
    def dfs(
        self,
        arr: List[int],
        n: int,
        curr: int,
        visited: List[bool]
    ):
        if self.status or curr >= n or curr < 0 or visited[curr]:
            return

        if arr[curr] == 0:
            self.status = True
            return

        offset = arr[curr]
        visited[curr] = True
        self.dfs(arr, n, curr - offset, visited)
        self.dfs(arr, n, curr + offset, visited)
        visited[curr] = False

    def canReach(self, arr: List[int], start: int) -> bool:
        n = len(arr)
        visited = [False] * n
        self.status = False

        self.dfs(arr, n, start, visited)

        return self.status
