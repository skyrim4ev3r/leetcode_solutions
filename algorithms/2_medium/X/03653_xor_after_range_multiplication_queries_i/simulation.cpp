class Solution {
    const static long long DIV{1'000'000'007};
public:
    static int xorAfterQueries(vector<int>& nums, vector<vector<int>>& queries) {
        for (const auto &query: queries) {
            size_t right{static_cast<size_t>(query[1])};
            size_t step{static_cast<size_t>(query[2])};
            long long v{static_cast<long long>(query[3])};

            for (size_t left{static_cast<size_t>(query[0])}; left <= right; left += step) {
                nums[left] = static_cast<int>(static_cast<long long>(nums[left]) * v % DIV);
            }
        }

        int res{0};

        for (const int &num: nums) {
            res ^= num;
        }

        return res;
    }
};
