class Solution {
public:
    static int jump(const vector<int>& nums) {
        const size_t len = nums.size();
        size_t right = 0;
        size_t left = 0;
        int steps = 0;

        while (right + 1 < len) {
            size_t new_right = 0;
            while (left <= right) {
                new_right = std::max(new_right, left + nums[left]);
                left += 1;
            }
            // If new_right <= right there is no progress — indicates invalid input.
            right = new_right;
            steps += 1;
        }

        return steps;
    }
};
