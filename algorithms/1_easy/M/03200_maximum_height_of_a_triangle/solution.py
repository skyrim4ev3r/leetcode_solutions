class Solution:
    def maxHeightOfTriangle(self, red: int, blue: int) -> int:
        curr_height = 0
        odd_count = 0
        even_count = 0
        curr_level = 1

        while True:
            if (curr_level & 1) == 1:
                odd_count += curr_level
            else:
                even_count += curr_level

            if not ((odd_count <= red and even_count <= blue) or (odd_count <= blue and even_count <= red)):
                return curr_level - 1

            curr_level += 1
