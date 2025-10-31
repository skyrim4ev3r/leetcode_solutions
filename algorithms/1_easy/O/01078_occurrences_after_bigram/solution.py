class Solution:
    def findOcurrences(self, text: str, first: str, second: str) -> List[str]:

        parts = text.split()
        parts_len = len(parts)
        res = []

        for i in range(2, parts_len):
            if parts[i - 2] == first and parts[i - 1] == second:
                res.append(parts[i])

        return res
