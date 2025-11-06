class Solution {
public:
    vector<int> leftRightDifference(vector<int>& nums) {
        int sum{0};
        const size_t len{nums.size()};
        vector<int>res(len, 0);

        for (size_t i{0}; i < len; ++i)  {
            res[i] += sum;
            sum += nums[i];
        }

        sum = 0;
        for (size_t i{len - 1}; i < len; --i)  {
            res[i] = abs(res[i] - sum);
            sum += nums[i];
        }

        return res;
    }
};
