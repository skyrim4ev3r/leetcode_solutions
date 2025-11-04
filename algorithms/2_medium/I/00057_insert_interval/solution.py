class Solution:
    def insert(self, intervals: List[List[int]], new_interval: List[int]) -> List[List[int]]:
        res = []
        i = 0
        n = len(intervals)

        while i < n and intervals[i][1] < new_interval[0]:
            res.append(intervals[i])
            i += 1


        while i < n and intervals[i][0] <= new_interval[1]:
            if new_interval[0] > intervals[i][0]:
                new_interval[0] = intervals[i][0]
            if new_interval[1] < intervals[i][1]:
                new_interval[1] = intervals[i][1]
            i += 1

        res.append(new_interval)

        while i < n:
            res.append(intervals[i])
            i += 1

        return res
