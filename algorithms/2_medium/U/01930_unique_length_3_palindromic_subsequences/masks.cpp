class Solution {
public:
    int countPalindromicSubsequence(string s) {
        const size_t len{s.size()};
        array<bool, 26> is_seen{};
        array<int, 26> masks{};
        array<int, 26> scores{};

        for (size_t i{0}; i < len; ++i) {
            const size_t chr_index{static_cast<size_t>(s[i] - 'a')};
            const int mask{1 << chr_index};

            if (is_seen[chr_index]) {
                scores[chr_index] = __builtin_popcount(masks[chr_index]);
            }

            for (size_t j{0}; j< 26; ++j) {
                if (is_seen[j]) {
                    masks[j] |= mask;
                }
            }

            is_seen[chr_index] = true;
        }

        return reduce(scores.begin(), scores.end(), 0);
    }
};
