class Solution:
    def merge(self, intervals: List[List[int]]) -> List[List[int]]:

        intervals.sort(key=lambda x: x[0])

        res = []

        for interval in intervals:
            if len(res) > 0 and res[-1][1] >= interval[0]:
                if res[-1][1] < interval[1]:
                    res[-1][1] = interval[1]
            else:
                res.append(interval)

        return res
