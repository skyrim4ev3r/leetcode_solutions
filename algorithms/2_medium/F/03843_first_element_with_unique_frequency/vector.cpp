class Solution {
public:
    int firstUniqueFreq(vector<int>& nums) {
        const int max_num{ *std::max_element(nums.cbegin(), nums.cend()) };
        vector<int> freqs(static_cast<size_t>(max_num + 1), 0);

        for (const auto& num : nums) {
            freqs[static_cast<size_t>(num)] += 1;
        }

        const int max_freq{ *std::max_element(freqs.cbegin(), freqs.cend()) };
        vector<int> freqs_of_freqs(static_cast<size_t>(max_freq + 1), 0);

        for (const auto& freq : freqs) {
            freqs_of_freqs[static_cast<size_t>(freq)] += 1;
        }

        for (const auto& num : nums) {
            const int freq{ freqs[static_cast<size_t>(num)] };

            if (freqs_of_freqs[static_cast<size_t>(freq)] == 1) {
                return num;
            }
        }

        return -1;
    }
};
