class Solution:
    def removeCoveredIntervals(self, intervals: List[List[int]]) -> int:
        intervals.sort(key= lambda x: (x[0], -x[1]))

        n = len(intervals)
        invalids_count = 0
        prev_end = intervals[0][1]

        for i in range(1, n):
            if intervals[i][1] <=  prev_end:
                invalids_count += 1
            else:
                prev_end = intervals[i][1]

        return n - invalids_count
