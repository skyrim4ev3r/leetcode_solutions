class Solution {
public:
    int maxArea(vector<int>& height) {
        size_t left{0};
        size_t right{height.size() - 1};
        int max{0};

        while (left < right) {
            int height_l{height[left]};
            int height_r{height[right]};
            int curr_min_height = std::min(height_l, height_r);
            max = std::max(max, static_cast<int>(right - left) * curr_min_height);

            if (height_l < height_r) {
                left += 1;
            } else {
                right -= 1;
            }
        }

        return max;
    }
};
