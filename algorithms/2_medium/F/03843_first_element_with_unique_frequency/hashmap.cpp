class Solution {
public:
    int firstUniqueFreq(vector<int>& nums) {
        unordered_map<int, int> freqs{};

        for (const auto& num : nums) {
           freqs[num] += 1;
        }

        unordered_map<int, int> freqs_of_freqs{};

        for (const auto& [_, freq] : freqs) {
            freqs_of_freqs[freq] += 1;
        }

        for (const auto& num : nums) {
            const int freq{ freqs[num] };

            if (freqs_of_freqs[freq] == 1) {
                return num;
            }
        }

        return -1;
    }
};
