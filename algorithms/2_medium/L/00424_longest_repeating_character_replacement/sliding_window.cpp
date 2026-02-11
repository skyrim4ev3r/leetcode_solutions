class Solution {
public:
    int characterReplacement(string s, int k) {
        const size_t len{ s.size() };
        array<int, 26> freqs{};
        size_t left{ 0 };
        int curr_max_freq{ 0 };
        int res{ 0 };

        for (size_t right{ 0 }; right < len; ++right) {
            const int total{ static_cast<int>(right - left + 1) };
            freqs[static_cast<size_t>(s[right] - 'A')] += 1;
            curr_max_freq = std::max(curr_max_freq, freqs[static_cast<size_t>(s[right] - 'A')]);

            if (total - curr_max_freq > k) {
                freqs[static_cast<size_t>(s[left] - 'A')] -= 1;
                left += 1;
            } else {
                res = total;
            }
        }

        return res;
    }
};
