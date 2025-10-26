class Solution:
    def trap(self, height: List[int]) -> int:

        left_idx = 0
        right_idx = len(height) - 1
        left_height = height[left_idx]
        right_height = height[right_idx]
        total_sum = 0

        while left_idx + 1 < right_idx:
            if left_height < right_height:
                left_idx += 1
                new_height = height[left_idx]

                if left_height > new_height:
                    total_sum += left_height - new_height
                else:
                    left_height = new_height

            else:
                right_idx -= 1
                new_height = height[right_idx]

                if right_height > new_height:
                    total_sum += right_height - new_height
                else:
                    right_height = new_height

        return total_sum
