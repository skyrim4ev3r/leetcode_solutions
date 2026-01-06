class Solution {
public:
    long long largestPerimeter(vector<int>& nums) {
        ranges::sort(nums);
        long long sum {reduce(nums.begin(), nums.end(), 0LL)};

        for (size_t i {nums.size() - 1}; i > 1; --i) {
            const long long largest_side {static_cast<long long>(nums[i])};

            if (largest_side * 2 < sum) {
                return sum;
            }

            sum -= largest_side;
        }

        return -1;
    }
};
