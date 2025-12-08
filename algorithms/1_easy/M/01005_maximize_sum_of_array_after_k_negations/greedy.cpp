class Solution {
public:
    int largestSumAfterKNegations(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());

        const size_t len{nums.size()};
        size_t curr_index{0};

        while (curr_index < len && nums[curr_index] < 0 && k > 0) {
            nums[curr_index] *= -1;
            k -= 1;
            curr_index += 1;
        }

        int sum = reduce(nums.begin(), nums.end(), 0);

        if (k % 2 == 0) {
            return sum;
        }

        return sum - 2 * (*min_element(nums.begin(), nums.end()));
    }
};
