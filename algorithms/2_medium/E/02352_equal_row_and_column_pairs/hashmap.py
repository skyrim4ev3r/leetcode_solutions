class Solution:
    def equalPairs(self, grid: List[List[int]]) -> int:
        n = len(grid)
        hashmap = defaultdict(int)
        count = 0

        for j in range(n):
            column_tuple = tuple(grid[i][j] for i in range(n))
            hashmap[column_tuple] += 1

        for row in grid:
            val = hashmap.get(tuple(row))
            if val != None:
                count += val

        return count
