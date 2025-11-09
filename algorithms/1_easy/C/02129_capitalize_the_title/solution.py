class Solution:
    def capitalizeTitle(self, title: str) -> str:
        res = []

        for part in title.split():
            if len(part) < 3:
                res.append(part.lower())
            else:
                res.append(part.capitalize())

        return " ".join(res)
