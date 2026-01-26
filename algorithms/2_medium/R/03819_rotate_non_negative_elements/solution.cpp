class Solution {
public:
    vector<int> rotateElements(vector<int>& nums, int k) {
        const size_t nums_len{ nums.size() };
        vector<int> positive_vals{};

        for (const auto& num : nums) {
            if (num >= 0) {
                positive_vals.push_back(num);
            }
        }

        const size_t positive_len{ positive_vals.size() };

        if (positive_len == 0) {
            return nums;
        }

        k %= static_cast<int>(positive_len);
        std::rotate(
            positive_vals.begin(),
            positive_vals.begin() + static_cast<size_t>(k),
            positive_vals.end()
        );

        size_t positive_index{ 0 };

        for (size_t nums_index{ 0 };  nums_index < nums_len; ++nums_index) {
            if (nums[nums_index] >= 0) {
                nums[nums_index] = positive_vals[positive_index];
                positive_index += 1;
            }
        }

        return nums;
    }
};
