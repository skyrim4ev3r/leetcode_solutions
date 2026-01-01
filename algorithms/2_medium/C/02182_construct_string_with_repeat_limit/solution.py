class Solution:
    def repeatLimitedString(self, s: str, repeat_limit: int) -> str:
        res = []
        freqs = [0] * 26

        for ch in s:
            freqs[ord(ch) - ord('a')] += 1

        stack = []

        for i in range(26):
            if freqs[i] > 0:
                stack.append([chr(i + ord('a')), freqs[i]])

        while stack:
            (ch, freq) = stack.pop()
            while freq != 0:
                curr_repeat = min(repeat_limit, freq)
                freq -= curr_repeat

                for i in range(curr_repeat):
                    res.append(ch)

                if freq > 0:
                    if stack:
                        res.append(stack[-1][0])
                        stack[-1][1] -= 1

                        if stack[-1][1] == 0:
                            stack.pop()
                    else:
                        return "".join(res)

        return "".join(res)
