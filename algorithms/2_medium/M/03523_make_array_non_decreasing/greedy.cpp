class Solution {
public:
    int maximumPossibleSize(vector<int>& nums) {
        const int total_count{ static_cast<int>(nums.size()) };
        int curr_max{ numeric_limits<int>::min() };
        int remove_count{ 0 };

        for (const auto& num : nums) {
            curr_max = std::max(curr_max, num);

            if (num < curr_max) {
                remove_count += 1;
            }
        }

        return total_count - remove_count;
    }
};
