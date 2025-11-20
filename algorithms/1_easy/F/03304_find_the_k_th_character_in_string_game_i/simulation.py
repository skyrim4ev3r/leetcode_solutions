class Solution:
    def kthCharacter(self, k: int) -> str:
        res = [ord('a')]

        while len(res) < k:
            for i in range(len(res)):
                res.append(res[i] + 1)

        return chr(res[k - 1])
