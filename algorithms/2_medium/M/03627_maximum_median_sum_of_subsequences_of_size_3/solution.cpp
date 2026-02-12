// 1- Sort array
// 2- Choose two largest and one smallest for each sub-array, and second largest will be median
// 3- Add 2nd largest to sum as median

class Solution {
public:
    static long long maximumMedianSum(vector<int>& nums) {
        ranges::sort(nums);

        long long sum{ 0 };
        const auto crbegin{ nums.crbegin() + 1 };
        const auto crend{ nums.crbegin() + 1 + 2 * (nums.size() / 3) };

        for (auto it{ crbegin }; it < crend ; it += 2) {
            sum += *it;
        }

        return sum;
    }
};
