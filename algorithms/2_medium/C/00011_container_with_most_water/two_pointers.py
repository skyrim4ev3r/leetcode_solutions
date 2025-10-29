class Solution:
    def maxArea(self, height: List[int]) -> int:
        left = 0
        right = len(height) - 1
        max_area = 0

        while left < right:
            height_l = height[left]
            height_r = height[right]
            curr_min_height = height_l if height_l < height_r else height_r
            curr_area = (right - left) * curr_min_height

            if max_area < curr_area:
                max_area = curr_area

            if height_l < height_r:
                left += 1
            else:
                right -= 1

        return max_area
