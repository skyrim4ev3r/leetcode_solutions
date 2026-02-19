class Solution {
public:
    static vector<int> minBitwiseArray(const vector<int>& nums) {
        const size_t len{ nums.size() };
        vector<int> res(len, 0);

        for (size_t i{ 0 }; i < len; ++i) {
            const int num{ nums[i] };

            if (num == 2) {
                res[i] = -1; // Special case for prime number 2
            } else {
                int mask{ 1 };
                // Find the lowest bit that is 0
                while ((num & mask) != 0) {
                    mask = mask << 1;
                }
                mask = mask >> 1; // Move back to the last bit that was 1
                res[i] = (num ^ mask); // Toggle that bit
            }
        }

        return res;
    }
};
