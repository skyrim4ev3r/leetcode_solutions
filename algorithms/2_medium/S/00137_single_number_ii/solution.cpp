const int INPUT_BITS{ 32 };

class Solution {
public:
    static int singleNumber(vector<int>& nums) {
        int32_t res{ 0 };
        array<int32_t, INPUT_BITS> freqs_bits{};

        for (const auto& num : nums) {
            for (size_t i{ 0 }; i < INPUT_BITS; ++i) {
                if ((num & (1 << i)) != 0) {
                    freqs_bits[i] += 1;
                }
            }
        }

        for (size_t i{ 0 }; const auto& freq : freqs_bits) {
            if (freq % 3 != 0) {
                res |= (1 << i);
            }

            ++i;
        }

        return res;
    }
};
