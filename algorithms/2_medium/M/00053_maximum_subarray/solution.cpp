class Solution {
public:
    static int maxSubArray(const vector<int>& nums) {
        int sum = 0;
        int max = numeric_limits<int>::min();

        for(const int& num : nums) {
            sum += num;
            max = std::max(max, sum);
            sum = std::max(sum, 0);
        }

        return max;
    }
};
