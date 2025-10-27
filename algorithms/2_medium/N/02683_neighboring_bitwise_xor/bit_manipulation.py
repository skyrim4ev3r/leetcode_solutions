class Solution:
    def doesValidArrayExist(self, derived: List[int]) -> bool:
        res = 0
        for x in derived:
            res ^= x
        return res == 0
