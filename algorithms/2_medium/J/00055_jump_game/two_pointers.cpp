class Solution {
public:
    bool canJump(vector<int>& nums) {

        const size_t len{nums.size()};
        size_t left{0};
        size_t right{0};

        while (right < len - 1) {
            size_t max_jump{0};
            for (size_t i{left}; i <= right; ++i) {
                max_jump = max(max_jump, i + static_cast<size_t>(nums[i]));
            }

            if (max_jump == right) {
                return false;
            }

            left = right + 1;
            right = max_jump;
        }

        return true;
    }
};
