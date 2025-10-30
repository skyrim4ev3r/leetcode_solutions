class Solution {
public:
    long long countSubarrays(vector<int>& nums, long long k) {
        long long count{0};
        size_t left{0};
        size_t right{0};
        long long total_sum{0};
        const size_t nums_len{nums.size()};

        while (left < nums_len) {
            while (right < nums_len && (total_sum + nums[right]) * (right - left + 1) < k) {
                total_sum += nums[right];
                right += 1;
            }

            count += (right - left);

            total_sum -= nums[left];
            left += 1;

            if (right < left) {
                right = left;
                total_sum = 0;
            }
        }

        return count;
    }
};
