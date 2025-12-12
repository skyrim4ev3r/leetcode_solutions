class Solution {
public:
    int countLargestGroup(int n) {
        unordered_map<int, int> freqs{};

        for (int i{1}; i <= n; ++i) {
            int temp{i};
            int dig_sum{0};

            while (temp > 0) {
                dig_sum += temp % 10;
                temp /= 10;
            }

            freqs[dig_sum] += 1;
        }

        int max_freq{0};
        int max_freq_count{0};

        for (const auto& it : freqs) {
            if (max_freq < it.second) {
                max_freq = it.second;
                max_freq_count = 1;
            } else if (max_freq == it.second) {
                max_freq_count += 1;
            }
        }

        return max_freq_count;
    }
};
