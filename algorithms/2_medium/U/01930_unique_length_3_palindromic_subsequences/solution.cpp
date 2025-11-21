class Solution {
public:
    int countPalindromicSubsequence(string s) {
        const size_t len{s.size()};
        array<bool, 26> is_seen_first{};
        int count{0};

        for (size_t i{0}; i < len; ++i) {
            if ( is_seen_first[static_cast<size_t>(s[i] - 'a')] ) {
                continue;
            }

            is_seen_first[static_cast<size_t>(s[i] - 'a')] = true;

            size_t k{len -1};
            while (k > i && s[k] != s[i]) {
                k -= 1;
            }

            array<bool, 26> is_seen_second{};

            for (size_t j{i + 1}; j < k; ++j) {
                if ( !is_seen_second[static_cast<size_t>(s[j] - 'a')] ) {
                    count += 1;
                    is_seen_second[static_cast<size_t>(s[j] - 'a')] = true;
                }
            }
        }

        return count;
    }
};
