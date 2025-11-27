class Solution:
    def numberOfPoints(self, nums: List[List[int]]) -> int:
        nums.sort(key=lambda x: x[0])
        count = 0
        prev_right_point = -sys.maxsize -1

        for point in nums:
            if prev_right_point >=  point[1]:
                continue

            if prev_right_point >=  point[0]:
                count += point[1] - prev_right_point
                prev_right_point = point[1]
            else:
                count += point[1] - point[0] + 1
                prev_right_point = point[1]

        return count
