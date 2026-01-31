class Solution:
    def powerfulIntegers(self, x: int, y: int, bound: int) -> List[int]:
        i = 1
        res = set()

        while i < bound:
            j = 1

            while j + i <= bound:
                res.add(i + j)
                j *= y

                if y == 1:
                    break
            i *= x
            if x == 1:
                break

        return list(res)
