class Solution {
public:
    static long long findMaximumScore(const vector<int>& nums) {
        long long curr_max{ 0 };
        long long score{ 0 };

        for (const auto& num : nums) {
            score += curr_max;
            curr_max = std::max(curr_max, static_cast<long long>(num));
        }

        return score;
    }
};
