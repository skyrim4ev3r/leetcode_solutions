class Solution {
public:
    static bool increasingTriplet(const vector<int>& nums) {
        int mid_val = numeric_limits<int>::max();
        int min_val = numeric_limits<int>::max();

        for (const auto curr_val : nums) {
            if (curr_val > mid_val) {
                return true;
            }

            if (curr_val < min_val) {
                min_val = curr_val;
            } else if (curr_val > min_val && curr_val < mid_val) {
                mid_val = curr_val;
            }
        }

        return false;
    }
};
