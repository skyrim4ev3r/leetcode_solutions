class Solution:
    def checkValidCuts(self, n: int, rectangles: List[List[int]]) -> bool:
        rectangles.sort(key=lambda x: x[1])

        count = 1
        prev_end = rectangles[0][3]

        for rectangle in rectangles:
            if rectangle[1] < prev_end:
                prev_end = max(prev_end, rectangle[3])
            else:
                count += 1

                if count == 3:
                    return True

                prev_end = rectangle[3]

        rectangles.sort(key=lambda x: x[0])
        count = 1
        prev_end = rectangles[0][2]

        for rectangle in rectangles:
            if rectangle[0] < prev_end:
                prev_end = max(prev_end, rectangle[2])
            else:
                count += 1

                if count == 3:
                    return True

                prev_end = rectangle[2]

        return False
