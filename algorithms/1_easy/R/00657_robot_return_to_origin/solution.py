class Solution:
    def judgeCircle(self, moves: str) -> bool:

        if (len(moves) & 1) == 1:
            return False

        lr = 0
        ud = 0

        for ch in moves:
            match ch:
                case 'U':
                    ud += 1
                case 'D':
                    ud -= 1
                case 'R':
                    lr += 1
                case 'L':
                    lr -= 1

        return lr == 0 and ud == 0
