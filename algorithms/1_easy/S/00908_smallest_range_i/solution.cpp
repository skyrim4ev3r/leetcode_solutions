class Solution {
public:
    int smallestRangeI(vector<int>& nums, int k) {
        int min_num{INT_MAX};
        int max_num{INT_MIN};

        for (const int &num: nums) {
            max_num = max(max_num, num);
            min_num = min(min_num, num);
        }
        return max(0, (max_num - min_num) - 2 * k);
    }
};
