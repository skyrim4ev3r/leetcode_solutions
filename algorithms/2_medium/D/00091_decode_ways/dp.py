class Solution:
    def solve(self, mem, s, pos):
        if pos == len(s):
            return 1
        if mem[pos] > -1:
            return mem[pos]
        if s[pos] == '0':
            mem[pos] = 0
            return 0
        res = self.solve(mem, s, pos+1)
        if pos < len(s) - 1 and (s[pos] == '1' or (s[pos] == '2' and ord(s[pos + 1]) < ord('7'))):
            res += self.solve(mem, s, pos+2)
        mem[pos] = res
        return res

    def numDecodings(self, s: str) -> int:
        mem = [-1 for _ in range(len(s))]
        return self.solve(mem, s, 0)
