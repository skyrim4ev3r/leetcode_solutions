class Solution:
    def minimumSwap(self, s1: str, s2: str) -> int:
        xy = 0 # x in s1, y in s2
        yx = 0 # y in s1, x in s2
        n = len(s1)

        for i in range(n):
            if s1[i] == 'x' and s2[i] == 'y':
                xy += 1
            elif s1[i] == 'y' and s2[i] == 'x':
                yx += 1

        if ((xy + yx) & 1) == 1:
            return -1

        return (xy // 2) + (yx // 2) + (xy & 1) + (yx & 1)
