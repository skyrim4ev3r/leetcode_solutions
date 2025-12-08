class Solution:
    def isBoomerang(self, points: List[List[int]]) -> bool:
        dx1 = points[1][0] - points[0][0]
        dy1 = points[1][1] - points[0][1]

        dx2 = points[2][0] - points[0][0]
        dy2 = points[2][1] - points[0][1]

        if (dx1 == 0 and dx2 == 0) or (dx1 == 0 and dy1 == 0) or (dx2 == 0 and dy2 == 0):
            return False

        return dx1 == 0 or dx2 == 0 or (dy1 / dx1) != (dy2 / dx2)
