class Solution {
public:
    int findLHS(vector<int>& nums) {
        const size_t len{ nums.size() };
        unordered_map<int, int> freqs{};

        for (const auto& num : nums) {
            freqs[num] += 1;
        }

        int longest{ 0 };

        for (const auto& [val, freq] : freqs) {
            const auto& it_next{ freqs.find(val + 1) };
            if (it_next != freqs.end()) {
                longest = std::max(longest, freq + it_next->second);
            }

            const auto& it_prev{ freqs.find(val - 1) };
            if (it_prev != freqs.end()) {
                longest = std::max(longest, freq + it_prev->second);
            }
        }

        return longest;
    }
};
