class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int prev_max{ 1 };
        int prev_min{ 1 };
        int max_prod{ numeric_limits<int>::min() };

        for (const auto& num : nums) {
            const int curr_min{ std::min(num, std:: min(num * prev_min, num * prev_max)) };
            const int curr_max{ std::max(num, std:: max(num * prev_min, num * prev_max)) };

            max_prod = std::max(max_prod, curr_max);
            prev_max = curr_max;
            prev_min = curr_min;
        }

        return max_prod;
    }
};
