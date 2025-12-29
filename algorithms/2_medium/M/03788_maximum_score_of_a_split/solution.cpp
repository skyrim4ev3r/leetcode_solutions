class Solution {
public:
    long long maximumScore(vector<int>& nums) {
        const size_t len {nums.size()};
        vector<int> min_suffix(len, 0);
        min_suffix[len - 1] = nums[len - 1];

        for (size_t i {len - 2}; i < len; --i) {
            min_suffix[i] = std::min(min_suffix[i + 1], nums[i]);
        }

        long long prefix {0};
        long long max_score {numeric_limits<long long>::min()};

        for (size_t i {0}; i + 1 < len; ++i) {
            prefix += static_cast<long long>(nums[i]);
            max_score = std::max(max_score, prefix - static_cast<long long>(min_suffix[i + 1]));
        }

        return max_score;
    }
};
