class Solution:
    def maxDistance(self, moves: str) -> int:
        lr = 0
        ud = 0
        extra = 0

        for ch in moves:
            match ch:
                case 'U': ud += 1
                case 'D': ud -= 1
                case 'R': lr += 1
                case 'L': lr -= 1
                case '_': extra += 1

        return abs(ud) + abs(lr) + extra
