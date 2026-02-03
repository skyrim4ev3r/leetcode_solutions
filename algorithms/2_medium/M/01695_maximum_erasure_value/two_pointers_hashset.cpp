class Solution {
public:
    int maximumUniqueSubarray(vector<int>& nums) {
        unordered_set<int> hashset{};
        int max_sum{ 0 };
        int curr_sum{ 0 };
        size_t left{ 0 };
        const size_t len{ nums.size() };

        for (size_t right{ 0 }; right < len; ++right) {
            const int num{ nums[right] };

            while (hashset.contains(num)) {
                hashset.erase(nums[left]);
                curr_sum -= nums[left];
                left += 1;
            }

            curr_sum += num;
            hashset.insert(num);
            max_sum = std::max(max_sum, curr_sum);
        }

        return max_sum;
    }
};
