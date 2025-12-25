class Solution:
    def partitionString(self, s: str) -> List[str]:
        seen = set()
        res = []
        part = ""

        for ch in s:
            part += ch
            if not part in seen:
                seen.add(part)
                res.append(part)
                part = ""

        return res
