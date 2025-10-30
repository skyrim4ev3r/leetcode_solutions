from heapq import heappush, heappop
import sys

INT_MAX = sys.maxsize

class Cell:
    def __init__(self, cost, i, j):
        self.cost = cost
        self.i = i
        self.j = j

    def __eq__(self, other):
        if isinstance(other, Cell):
            return self.i == other.i and self.j == other.j
        return False

    def __lt__(self, other):
        if isinstance(other, Cell):
            return self.cost < other.cost
        return True

class Solution:
    def minCost(self, grid: List[List[int]]) -> int:
        rows = len(grid)
        cols = len(grid[0])

        directions = [[0, 1], [0, -1], [1, 0], [-1, 0]]
        directions_len = len(directions)
        cost_matrix = [[INT_MAX] * cols for _ in range(rows)]
        heap = []

        heappush(heap,Cell(0, 0, 0))
        cost_matrix[0][0] = 0

        while heap:
            cell = heappop(heap)

            if cell.i == rows - 1 and cell.j == cols - 1:
                return cell.cost

            for index in range(directions_len):
                new_i = cell.i + directions[index][0]
                new_j = cell.j + directions[index][1]

                if new_i >= rows or new_j >= cols or new_i < 0 or new_j < 0:
                    continue

                new_cost = cell.cost if index == (grid[cell.i][cell.j] - 1) else cell.cost + 1

                if new_cost < cost_matrix[new_i][new_j]:
                    cost_matrix[new_i][new_j] = new_cost
                    heappush(heap, Cell(new_cost, new_i, new_j))

        return -1
