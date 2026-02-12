class Solution {
public:
    static int longestBalanced(const string& s) {
        const size_t len{ s.size() };
        size_t longest{ 0 };

        for (size_t i{ 0 }; i < len; ++i) {
            array<int, 26> freqs{};

            for (size_t j{ i }; j < len; ++j) {
                const size_t freq_index{ static_cast<size_t>(s[j] - 'a') };
                freqs[freq_index] += 1;
                const int curr_freq{ freqs[freq_index] };
                const bool is_valid{ std::all_of(freqs.cbegin(), freqs.cend(), [&curr_freq](const auto& freq) {
                    return freq == 0 || freq == curr_freq;
                }) };

                if (is_valid) {
                    longest = std::max(longest, j - i + 1);
                }
            }
        }

        return static_cast<int>(longest);
    }
};
