MAX_WIDTH = 100

class Solution:
    def numberOfLines(self, widths: List[int], s: str) -> List[int]:
        lines_count = 1
        curr_width = 0

        for ch in s:
            char_width = widths[ord(ch) - ord('a')]

            if curr_width + char_width <= MAX_WIDTH:
                curr_width += char_width
            else:
                lines_count += 1
                curr_width = char_width

        return [lines_count, curr_width]
