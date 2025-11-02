class Solution:
    def imageSmoother(self, img: List[List[int]]) -> List[List[int]]:
        rows = len(img)
        cols = len(img[0])

        res = [[0] * cols for _ in range(rows)]
        directions = [[0, -1], [0, 1], [1, -1], [1, 0], [1, 1], [-1, -1], [-1, 0], [-1, 1]]

        for i in range(rows):
            for j in range(cols):
                total_sum = img[i][j]
                count = 1

                for direction in directions:
                    new_i = i + direction[0]
                    new_j = j + direction[1]

                    if new_i < 0 or new_j < 0 or new_i >= rows or new_j >= cols:
                        continue

                    count += 1
                    total_sum += img[new_i][new_j]

                res[i][j] = total_sum // count

        return res
