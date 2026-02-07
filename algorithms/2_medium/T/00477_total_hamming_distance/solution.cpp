const size_t BITS_COUNT{ 32 };

class Solution {
public:
    int totalHammingDistance(vector<int>& nums) {
        const int len_i32{ static_cast<int>(nums.size()) };
        int res{ 0 };

        for (size_t shift{ 0 }; shift < BITS_COUNT; ++shift) {
            const int mask{ 1 << shift };
            int count{ 0 };

            for (const auto& num : nums) {
                if ((num & mask) != 0) {
                    count += 1;
                }
            }

            res += ((len_i32 - count) * count);
        }

        return res;
    }
};
