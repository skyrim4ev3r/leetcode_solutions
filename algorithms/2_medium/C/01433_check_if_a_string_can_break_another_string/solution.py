class Solution:
    def checkIfCanBreak(self, s1: str, s2: str) -> bool:
        def check_break(freqs1, freqs2) -> bool:
            sum1 = 0
            sum2 = 0

            for i in range(25, -1, -1):
                sum1 += freqs1[i]
                sum2 += freqs2[i]

                if sum2 < sum1:
                    return False

            return True

        freqs_s1 = [0] * 26
        freqs_s2 = [0] * 26

        for ch in s1:
            freqs_s1[ord(ch) - ord('a')] += 1

        for ch in s2:
            freqs_s2[ord(ch) - ord('a')] += 1

        return check_break(freqs_s1, freqs_s2) or check_break(freqs_s2, freqs_s1)
