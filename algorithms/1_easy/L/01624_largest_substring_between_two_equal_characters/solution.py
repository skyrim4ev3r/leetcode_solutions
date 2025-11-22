class Solution:
    def maxLengthBetweenEqualCharacters(self, s: str) -> int:
        chars_pos = [[-1, -1] for _ in range(26)]
        max_dis = -1

        for i, ch in enumerate(s):
            chars_pos_index = ord(ch) - ord('a')

            if chars_pos[chars_pos_index][0] == -1:
                chars_pos[chars_pos_index][0] = i
            else:
                chars_pos[chars_pos_index][1] = i
                max_dis = max(max_dis, chars_pos[chars_pos_index][1] - chars_pos[chars_pos_index][0] - 1)

        return max_dis
