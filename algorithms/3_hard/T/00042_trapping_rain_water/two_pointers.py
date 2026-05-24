class Solution:
    def trap(self, height: List[int]) -> int:
        left = 0
        right = len(height) - 1
        curr_max_left = 0
        curr_max_right = 0
        total = 0

        while left < right:
            if height[left] < height[right]:
                if curr_max_left > height[left]:
                    total += curr_max_left - height[left];
                else:
                    curr_max_left = height[left]
                left += 1
            else:
                if curr_max_right > height[right]:
                    total += curr_max_right - height[right]
                else:
                    curr_max_right = height[right]
                right -= 1

        return total
