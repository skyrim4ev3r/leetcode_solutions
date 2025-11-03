class Solution {
public:
    int maxFrequencyElements(vector<int>& nums) {
        unordered_map<int, int> freqs{};

        for (const int &num: nums) {
            freqs[num] += 1;
        }

        int max_freq{0};
        int total{0};

        for (const auto &[_, freq]: freqs) {
            if (freq > max_freq) {
                total = freq;
                max_freq = freq;
            } else if (freq == max_freq) {
                total += freq;
            }
        }

        return total;
    }
};
