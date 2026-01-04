class Solution {
public:
    static int minimumPushes(const string& word) {
        array<int, 26> freqs;
        std::ranges::fill(freqs, 0);

        for (const char& ch : word) {
            freqs[static_cast<size_t>(ch - 'a')] += 1;
        }

        ranges::sort(freqs, [](const auto& a, const auto& b) {
            return a > b;
        });

        return reduce(freqs.begin(), freqs.begin() + 8, 0) +
               reduce(freqs.begin() + 8, freqs.begin() + 16, 0) * 2 +
               reduce(freqs.begin() + 16, freqs.begin() + 24, 0) * 3 +
               reduce(freqs.begin() + 24, freqs.end(), 0) * 4;
    }
};
