class Solution {
public:
    int countPartitions(vector<int>& nums) {
        const size_t len{nums.size()};
        int r_sum{reduce(nums.begin(), nums.end(), 0)};
        int l_sum{0};
        int count{0};

        for (size_t i{0}; i < len - 1; ++i) {
            l_sum += nums[i];
            r_sum -= nums[i];

            if ((r_sum - l_sum) % 2 == 0) {
                count += 1;
            }
        }

        return count;
    }
};
