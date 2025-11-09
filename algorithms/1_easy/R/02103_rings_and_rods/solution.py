class Solution:
    def countPoints(self, rings: str) -> int:
        rings_len = len(rings)
        colors = [1, 2, 4]

        rods = [0] * 10

        for i in range(0, rings_len, 2):
            rod_index = ord(rings[i + 1]) - ord('0')
            color_index =  0 if rings[i] == 'R' else 1 if rings[i] == 'G' else 2
            rods[rod_index] |= colors[color_index]

        count = 0

        for rod in rods:
            if rod == 7:
                count += 1

        return count
