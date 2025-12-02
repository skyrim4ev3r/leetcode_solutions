class Solution {
public:
    vector<int> numberOfPairs(vector<int>& nums) {
        unordered_map<int, int> freqs{};
        int count_pair{0};
        int count_leftover{0};

        for (const int& num : nums) {
            freqs[num] += 1;
        }

        for (const auto& [_, freq] : freqs) {
            count_pair += freq / 2;
            count_leftover += (freq & 1);
        }

        return vector<int>{count_pair, count_leftover};
    }
};
