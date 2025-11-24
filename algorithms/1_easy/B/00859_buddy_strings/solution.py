class Solution:
    def buddyStrings(self, s: str, goal: str) -> bool:
        if len(s) != len(goal):
            return False

        n = len(s)
        diff = []
        freqs = [0] * 26

        for i in range(n):
            if s[i] != goal[i]:
                if len(diff) == 2:
                    return False

                diff.append(i)

            freqs[ord(s[i]) - ord('a')] += 1

        if len(diff) == 2:
            if s[diff[0]] == goal[diff[1]] and s[diff[1]] == goal[diff[0]]:
                return True
            else:
                return False

        if len(diff) == 0:
            for freq in freqs:
                if freq > 1:
                    return True

        return False
