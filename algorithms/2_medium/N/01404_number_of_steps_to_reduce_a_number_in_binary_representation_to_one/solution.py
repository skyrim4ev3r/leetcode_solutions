class Solution:
    def numSteps(self, s: str) -> int:
        s = list(s)
        count = 0

        while len(s) > 1 and s[-1] == '0':
            count += 1
            s.pop()

        return count + len(s) + 1 + s.count('0') if len(s) > 1 else count
