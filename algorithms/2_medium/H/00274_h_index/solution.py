class Solution:
    def hIndex(self, citations: List[int]) -> int:
        citations.sort(reverse=True)

        res = 0

        for (i, citation) in enumerate(citations):
            count = (i + 1)

            if citation >= count:
                res = count
            else:
                break

        return res
