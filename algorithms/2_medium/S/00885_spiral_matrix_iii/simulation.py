class Solution:
    def spiralMatrixIII(self, rows: int, cols: int, i: int, j: int) -> List[List[int]]:
        target_len = rows * cols
        res = []
        DIRECTIONS = [(0, 1), (1, 0), (0, -1), (-1, 0)]
        dir_index = 0
        curr_path_len = 0
        flip_flop_should_increase_path = True

        while True:
            if flip_flop_should_increase_path:
                curr_path_len += 1
            flip_flop_should_increase_path = not flip_flop_should_increase_path;

            for _ in range(curr_path_len):
                if i >= 0 and i < rows and j >=0 and j < cols:
                    res.append([i, j])

                    if len(res) == target_len:
                        return res

                i += DIRECTIONS[dir_index][0]
                j += DIRECTIONS[dir_index][1]

            dir_index = (dir_index + 1) % 4

        return res
