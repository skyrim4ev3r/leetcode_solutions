class Solution:
    def countGoodRectangles(self, rectangles: List[List[int]]) -> int:
        count = 0
        max_len = -1

        for rec in rectangles:
            curr_len = min(rec[0], rec[1])

            if max_len < curr_len:
                max_len = curr_len
                count = 1
            elif max_len == curr_len:
                count += 1

        return count
