class Solution:
    def buildArray(self, target: List[int], n: int) -> List[str]:
        target_len = len(target)
        i = 0
        num = 1
        res = []

        while i < target_len:
            res.append("Push")

            if num == target[i]:
                i += 1
            else:
                res.append("Pop")

            num += 1

        return res
