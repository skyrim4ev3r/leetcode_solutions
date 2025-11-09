class Solution:
    def maxDistance(self, colors: List[int]) -> int:
        colors_len = len(colors)

        right = colors_len - 1
        while right > 0 and colors[right] == colors[0]:
            right -= 1

        left = 0
        while left < colors_len - 1 and colors[left] == colors[colors_len - 1]:
            left += 1

        return max(right, colors_len - 1 - left)
