class Solution {
public:    
    int trap(vector<int>& height) {
        
        size_t left_idx = 0;
        size_t right_idx = height.size() - 1;
        int left_height = height[left_idx];
        int right_height = height[right_idx];
        int sum = 0;

        while (left_idx + 1 < right_idx) {
            if (left_height < right_height) {
                left_idx += 1;
                int new_height = height[left_idx];

                if (left_height > new_height) {
                    sum += left_height - new_height;
                } else {
                    left_height = new_height;
                }

            } else {
                right_idx -= 1;
                int new_height = height[right_idx];

                if (right_height > new_height) {
                    sum += right_height - new_height;
                } else {
                    right_height = new_height;
                }
            }
        }

        return sum;
    }
};
