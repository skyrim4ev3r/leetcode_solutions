class Solution:
    def splitWordsBySeparator(self, words: List[str], separator: str) -> List[str]:
        res: List[str] = []

        for word in words:
            for part in word.split(separator):
                if part:
                    res.append(part)

        return res
