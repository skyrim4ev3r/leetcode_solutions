class Solution {
public:
    static bool canSortArray(const vector<int>& nums) {
        int curr_max{ numeric_limits<int>::min() };
        int prev_max{ numeric_limits<int>::min() };

        for (const auto& num : nums) {
            if (__builtin_popcount(curr_max) != __builtin_popcount(num)) {
                prev_max = curr_max;
                curr_max = num;
            } else {
                curr_max = std::max(curr_max, num);
            }

            if (num < prev_max) {
                return false;
            }
        }

        return true;
    }
};
