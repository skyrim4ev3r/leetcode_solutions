class Solution {
public:
    static bool checkStrings(const string& s1, const string& s2) {
        const size_t len {s1.size()};
        array<int, 26> balance_freqs_even_indices;
        array<int, 26> balance_freqs_odd_indices;
        ranges::fill(balance_freqs_even_indices, 0);
        ranges::fill(balance_freqs_odd_indices, 0);

        for (size_t i {0}; i < len; ++i) {
            if ((i & 1) == 0) {
                balance_freqs_even_indices[static_cast<size_t>(s1[i] - 'a')] += 1;
                balance_freqs_even_indices[static_cast<size_t>(s2[i] - 'a')] -= 1;
            } else {
                balance_freqs_odd_indices[static_cast<size_t>(s1[i] - 'a')] += 1;
                balance_freqs_odd_indices[static_cast<size_t>(s2[i] - 'a')] -= 1;
            }
        }

        for (size_t i {0}; i < 26; ++i) {
            if (balance_freqs_even_indices[i] != 0 || balance_freqs_odd_indices[i] != 0) {
                return false;
            }
        }

        return true;
    }
};
