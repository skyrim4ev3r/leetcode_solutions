class Solution:
    def checkStraightLine(self, coordinates: List[List[int]]) -> bool:

        list_len = len(coordinates)
        first_dy = coordinates[1][1] - coordinates[0][1]
        first_dx = coordinates[1][0] - coordinates[0][0]

        for i in range(2, list_len):
            curr_dy = coordinates[i][1] - coordinates[0][1]
            curr_dx = coordinates[i][0] - coordinates[0][0]

            if first_dy * curr_dx != first_dx * curr_dy:
                return False

        return True
