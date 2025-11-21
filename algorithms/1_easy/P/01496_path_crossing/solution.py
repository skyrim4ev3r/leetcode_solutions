class Solution:
    def isPathCrossing(self, path: str) -> bool:
        visited = {(0, 0)}
        i = 0
        j = 0

        for ch in path:
            match ch:
                case 'N': i -= 1
                case 'S': i += 1
                case 'E': j += 1
                case 'W': j -= 1

            if (i, j) in visited:
                return True

            visited.add((i, j))

        return False
