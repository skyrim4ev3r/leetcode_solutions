class Solution {
public:
    int maxSubArray(vector<int>& nums) {

        int sum{0}, max{INT_MIN};

        for(const int &num: nums) {
            sum += num;
            max = std::max(max, sum);
            sum = std::max(sum, 0);
        }

        return max;
    }
};
