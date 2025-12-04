class Solution:
    def countCollisions(self, directions: str) -> int:
        count = 0
        curr_r = 0
        curr_s = 0

        for ch in directions:
            match ch:
                case 'L':
                    if curr_r > 0:
                        count += curr_r + 1
                        curr_r = 0
                        curr_s = 1
                    elif curr_s != 0:
                            count += 1
                case 'R':
                    curr_r += 1
                case 'S':
                    count += curr_r
                    curr_r = 0
                    curr_s = 1

        return count
