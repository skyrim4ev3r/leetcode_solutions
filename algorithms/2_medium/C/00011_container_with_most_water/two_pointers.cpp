class Solution {
public:
    static int maxArea(const vector<int>& height) {
        int max_water = 0;
        size_t left = 0;
        size_t right = height.size() - 1;

        while (left < right) {
            const int hl = height[left];
            const int hr = height[right];
            const int min_height = std::min(hl, hr);
            const int curr_water = static_cast<int>(right - left) * min_height;
            max_water = std::max(max_water, curr_water);

            if (hl < hr) {
                left += 1;
            } else {
                right -= 1;
            }
        }

        return max_water;
    }
};
