DIRECTIONS = [(0, 1), (1, 0), (0, -1), (-1, 0)]

class Solution:
    def isRobotBounded(self, instructions: str) -> bool:
        x = 0
        y = 0
        curr_dir_index = 0

        for ch in instructions:
            if ch == 'G':
                (dx, dy) = DIRECTIONS[curr_dir_index]
                y += dy
                x += dx
            elif ch == 'L':
                curr_dir_index = 3 if curr_dir_index == 0 else curr_dir_index - 1
            else:
                curr_dir_index = 0 if curr_dir_index == 3 else curr_dir_index + 1

        return (x == 0 and y == 0) or curr_dir_index != 0
