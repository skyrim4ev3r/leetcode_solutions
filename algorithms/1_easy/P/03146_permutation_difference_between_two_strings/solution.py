class Solution:
    def findPermutationDifference(self, s: str, t: str) -> int:
        len_str = len(s)
        position_diff = [0] * 26
        ord_a = ord('a')

        for i in range(len_str):
            position_diff[ord(s[i]) - ord_a] -= i
            position_diff[ord(t[i]) - ord_a] += i

        return sum(abs(n) for n in position_diff)
