constexpr size_t map_len = 256; // Cover all possible unsigned char values (0–255)

class Solution {
public:
    static int lengthOfLongestSubstring(const string& s) {
        const ptrdiff_t len = std::ssize(s);
        ptrdiff_t last_seen[map_len];
        std::fill(std::begin(last_seen), std::end(last_seen), -1);
        ptrdiff_t longest_substr = 0;
        ptrdiff_t lo = 0;

        for (ptrdiff_t hi = 0; hi < len; hi += 1) {
            const ptrdiff_t idx = static_cast<ptrdiff_t>(static_cast<unsigned char>(s[hi]));
            lo = std::max(lo, last_seen[idx] + 1);
            longest_substr = std::max(longest_substr, hi - lo + 1);
            last_seen[idx] = hi;
        }

        return static_cast<int>(longest_substr);
    }
};
