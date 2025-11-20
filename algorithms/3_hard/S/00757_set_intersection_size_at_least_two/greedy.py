class Solution:
    def intersectionSizeTwo(self, intervals: List[List[int]]) -> int:
        intervals.sort(key=lambda x: x[1])
        count = 0
        max1 = -sys.maxsize - 1
        max2 = -sys.maxsize - 1

        for interval in intervals:
            if interval[0] == max1:
                max2 = max1
                count += 1
                max1 = interval[1]
            elif interval[0] > max1:
                max1 = interval[1]
                max2 = max1 - 1
                count += 2
            elif interval[0] > max2:
                max2 = max1
                max1 = interval[1]
                count += 1

        return count
