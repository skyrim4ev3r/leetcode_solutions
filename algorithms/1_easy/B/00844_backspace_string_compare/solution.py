class Solution:
    def custom_parse(self, s):
        final_s = []

        for ch in s:
            if ch == '#':
                if final_s:
                    final_s.pop()
            else:
                final_s.append(ch)

        return final_s

    def backspaceCompare(self, s: str, t: str) -> bool:
        return self.custom_parse(s) == self.custom_parse(t)
