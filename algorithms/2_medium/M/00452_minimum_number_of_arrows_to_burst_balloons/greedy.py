class Solution:
    def findMinArrowShots(self, points: List[List[int]]) -> int:
        points.sort(key=lambda x: x[1])

        points_len = len(points)
        count = 1
        prev_end = points[0][1]

        for i in range(1, points_len):
            if points[i][0] > prev_end:
                prev_end = points[i][1]
                count += 1

        return count
