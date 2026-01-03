class Solution:
    def queryResults(self, limit: int, queries: List[List[int]]) -> List[int]:
        n = len(queries)
        res = [0] * n
        freqs_colors = defaultdict(int)
        curr_colors = {}

        for (i, q) in enumerate(queries):
            x = q[0]
            new_color = q[1]
            old_color = curr_colors.get(x)

            if old_color != None:
                freqs_colors[old_color] -= 1

                if freqs_colors[old_color] == 0:
                    del freqs_colors[old_color]

            curr_colors[x] = new_color
            freqs_colors[new_color] += 1

            res[i] = len(freqs_colors)

        return res
