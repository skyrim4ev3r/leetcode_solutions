const size_t XOR_GROUP_SIZE{ 3 };

class Solution {
    static inline void calc_next_level(const vector<int>& nums, unordered_set<int>& unique_xors) {
        const vector<int> prev_unique_xors(unique_xors.begin(), unique_xors.end());
        unique_xors.clear();

        for (const auto& num : nums) {
            for (const auto& prev_unique_xor : prev_unique_xors) {
                unique_xors.insert(num ^ prev_unique_xor);
            }
        }
    }
public:
    static int uniqueXorTriplets(const vector<int>& nums) {
        unordered_set<int> unique_xors{};
        unique_xors.insert(0);

        for (size_t c{ 0 }; c < XOR_GROUP_SIZE; ++c) {
            calc_next_level(nums, unique_xors);
        }

        return static_cast<int>(unique_xors.size());
    }
};
