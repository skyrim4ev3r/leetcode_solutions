class Solution {
public:
    static int getLeastFrequentDigit(int n) {
        array<int, 10> freqs{};

        while (n > 0) {
            freqs[static_cast<size_t>(n % 10)] += 1;
            n /= 10;
        }

        int min_freq{ numeric_limits<int>::max() };
        size_t min_freq_index{ 0 };

        for (size_t i{ 0 }; i < 10; ++i) {
            if (freqs[i] != 0 && freqs[i] < min_freq) {
                min_freq = freqs[i];
                min_freq_index = i;
            }
        }

        return static_cast<int>(min_freq_index);
    }
};
