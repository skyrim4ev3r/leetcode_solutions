class Solution {
public:
    int maxAbsoluteSum(vector<int>& nums) {
        int min_sum{ 0 };
        int max_sum{ 0 };
        int curr_sum{ 0 };

        for (const auto& num : nums) {
            curr_sum += num;
            min_sum = std::min(min_sum, curr_sum);
            max_sum = std::max(max_sum, curr_sum);
        }

        return max_sum - min_sum;
    }
};
