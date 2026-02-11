class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        const int min_target_freq{ 1 + static_cast<int>(nums.size()) / 3 };
        unordered_map<int, int> freqs{};
        vector<int> res{};

        for (const auto& num : nums) {
            freqs[num] += 1;
        }

        for (const auto& [val, freq] : freqs) {
            if (freq >= min_target_freq) {
                res.push_back(val);
            }
        }

        return res;
    }
};
