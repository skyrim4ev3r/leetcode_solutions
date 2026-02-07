class Solution:
    def manhattan_dist(self, p1: List[int], p2: List[int]) -> int:
        return abs(p1[0] - p2[0]) + abs(p1[1] - p2[1])

    def is_square(self, sides: List[int], diags: List[int]) -> bool:
        return sides[0] == sides[1] and sides[1] == sides[2] and sides[2] == sides[3] and diags[0] == diags[1]

    def validSquare(self, p1: List[int], p2: List[int], p3: List[int], p4: List[int]) -> bool:
        d12 = self.manhattan_dist(p1, p2)
        d13 = self.manhattan_dist(p1, p3)
        d14 = self.manhattan_dist(p1, p4)
        d23 = self.manhattan_dist(p2, p3)
        d24 = self.manhattan_dist(p2, p4)
        d34 = self.manhattan_dist(p3, p4)

        if d12 == 0 or d13 == 0 or d14 == 0 or d23 == 0 or d24 == 0 or d34 == 0:
            return False

        sides1 = [d12, d13, d24, d34]
        diags1 = [d14, d23]

        sides2 = [d12, d14, d23, d34]
        diags2 = [d13, d24]

        sides3 = [d13, d14, d23, d24]
        diags3 = [d13, d24]

        return (
            self.is_square(sides1, diags1) or
            self.is_square(sides2, diags2) or
            self.is_square(sides3, diags3)
        )
