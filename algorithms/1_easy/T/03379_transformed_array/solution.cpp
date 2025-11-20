class Solution {
public:
    vector<int> constructTransformedArray(vector<int>& nums) {
        const size_t len{nums.size()};
        vector<int> res(len, 0);

        for (size_t i{0}; i < len; ++i) {
            int curr{nums[i]};

            if (curr != 0) {
                int steps = abs(curr) % static_cast<int>(len);

                if (curr < 0) {
                    steps *= -1;
                }

                int target_index = static_cast<int>(i) + steps;

                if (target_index < 0) {
                    target_index += static_cast<int>(len);
                } else if (target_index >= static_cast<int>(len)) {
                    target_index -= static_cast<int>(len);
                }

                res[i] = nums[static_cast<size_t>(target_index)];
            }
        }

        return res;
    }
};
