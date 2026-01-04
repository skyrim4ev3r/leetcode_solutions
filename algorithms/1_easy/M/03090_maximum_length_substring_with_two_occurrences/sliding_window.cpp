class Solution {
public:
    int maximumLengthSubstring(string s) {
        const size_t len {s.size()};
        array<int, 26> window_freqs;
        std::ranges::fill(window_freqs, 0);
        size_t left {0};
        size_t max {0};

        for (size_t right {0}; right < len; ++right) {
            const size_t index {static_cast<size_t>(s[right] - 'a')};
            window_freqs[index] += 1;

            while (window_freqs[index] > 2) {
                window_freqs[static_cast<size_t>(s[left] - 'a')] -= 1;
                left += 1;
            }

            max = std::max(max, right + 1 - left);
        }

        return static_cast<int>(max);
    }
};
