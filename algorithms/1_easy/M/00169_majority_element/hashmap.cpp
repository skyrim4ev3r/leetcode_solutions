class Solution {
public:
    static int majorityElement(const vector<int>& nums) {
        unordered_map<int, int> freqs{};
        int max_freq_num = 0;
        int max_freq_count = 0;

        for (const auto num: nums) {
            freqs[num] += 1;
        }

        for (const auto it : freqs) {
            if (it.second > max_freq_count) {
                max_freq_count = it.second;
                max_freq_num = it.first;
            }
        }

        return max_freq_num;
    }
};
