class Solution:
    def countPoints(self, points: List[List[int]], queries: List[List[int]]) -> List[int]:
        res = [0] * len(queries)

        for (i, query) in enumerate(queries):
            query_square = query[2] * query[2]
            count = 0

            for point in points:
                delta_x = query[0] - point[0]
                delta_y = query[1] - point[1]
                dis_square = delta_x * delta_x + delta_y * delta_y

                if dis_square <= query_square:
                    count += 1

            res[i] = count

        return res
