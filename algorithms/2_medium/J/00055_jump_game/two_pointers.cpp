class Solution {
public:
    static bool canJump(const vector<int>& nums) {
        const size_t len = nums.size();
        size_t right = 0;
        size_t left = 0;

        while (right + 1 < len) {
            size_t new_right = 0;

            while (left <= right) {
                new_right = std::max(new_right, left + nums[left]);
                left += 1;
            }

            if (new_right <= right) {
                return false;
            }

            right = new_right;
        }

        return true;
    }
};
