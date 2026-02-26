const size_t XOR_GROUP_SIZE{ 3 };
const size_t MAX_XOR_VALUE{ 2048 };

class Solution {
    static inline void calc_next_level(const vector<int>& nums, array<bool, MAX_XOR_VALUE>& unique_xors) {
        vector<int> prev_unique_xors;

        for (size_t i{ 0 }; i < MAX_XOR_VALUE; ++i) {
            if (unique_xors[i]) {
                prev_unique_xors.push_back(static_cast<int>(i));
            }
        }

        ranges::fill(unique_xors, false);

        for (const auto& num : nums) {
            for (const auto& prev_unique_xor : prev_unique_xors) {
                unique_xors[static_cast<size_t>(num ^ prev_unique_xor)] = true;
            }
        }
    }
public:
    static int uniqueXorTriplets(const vector<int>& nums) {
        array<bool, MAX_XOR_VALUE> unique_xors;
        ranges::fill(unique_xors, false);
        unique_xors[0] = true;

        for (size_t c{ 0 }; c < XOR_GROUP_SIZE; ++c) {
            calc_next_level(nums, unique_xors);
        }

        return static_cast<int>(ranges::count(unique_xors, true));
    }
};
