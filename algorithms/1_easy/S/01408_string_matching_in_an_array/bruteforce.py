class Solution:
    def stringMatching(self, words: List[str]) -> List[str]:
        n = len(words)
        res = []
        is_inserted = [False] * n

        for i in range(n):
            for j in range(n):
                if i == j or is_inserted[j]:
                    continue

                if words[i].find(words[j]) != -1:
                    res.append(words[j])
                    is_inserted[j] = True

        return res
