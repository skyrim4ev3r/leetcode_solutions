class Solution:
    def countTriples(self, n: int) -> int:
        count = 0

        for a in range(1, n + 1):
            for b in range(a, n + 1):
                c_square = a * a + b * b
                possible_c = int(sqrt(c_square))

                if possible_c > n:
                    break

                if possible_c * possible_c == c_square:
                    count += 2

        return count
