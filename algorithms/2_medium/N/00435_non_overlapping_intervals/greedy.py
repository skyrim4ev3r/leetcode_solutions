class Solution:
    def eraseOverlapIntervals(self, intervals: List[List[int]]) -> int:
        intervals.sort(key=lambda x: x[1])

        intervals_len = len(intervals)
        count = 0
        prev_end = intervals[0][1]

        for i in range(1, intervals_len):
            if intervals[i][0] >= prev_end:
                prev_end = intervals[i][1]
            else:
                count += 1

        return count
