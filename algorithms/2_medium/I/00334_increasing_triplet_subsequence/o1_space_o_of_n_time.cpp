class Solution {
public:
    bool increasingTriplet(vector<int>& nums) {

        int prev_valid_min{INT_MAX};
        int curr_min{INT_MAX};

        for (int &num: nums) {
            if (num > prev_valid_min) {
                return true;
            }

            if (num > curr_min) {
                prev_valid_min = std::min(prev_valid_min, num);
            } else {
                curr_min = num;
            }
        }
        return false;
    }
};
