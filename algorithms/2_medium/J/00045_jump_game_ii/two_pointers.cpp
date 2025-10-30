class Solution {
public:
    int jump(vector<int>& nums) {

        const size_t len{nums.size()};
        size_t left{0};
        size_t right{0};
        int count{0};

        while (right < len - 1) {
            size_t max_jump{0};

            for (size_t i{left}; i <= right; ++i) {
                max_jump = max(max_jump, i + static_cast<size_t>(nums[i]));
            }

            left = right + 1;
            right = max_jump;
            count += 1;
        }

        return count;
    }
};
