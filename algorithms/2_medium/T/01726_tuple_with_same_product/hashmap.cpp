class Solution {
public:
    int tupleSameProduct(vector<int>& nums) {
        unordered_map<int, int> hashmap{};
        const size_t len{ nums.size() };

        for (size_t i{ 0 }; i < len; ++i) {
            for (size_t j{ i + 1 }; j < len; ++j) {
                hashmap[(nums[i] * nums[j])] += 1;
            }
        }

        int res{ 0 };

        for (const auto& [_, freq] : hashmap) {
            res += ((freq * (freq - 1)) / 2) * 8;
        }

        return res;
    }
};
