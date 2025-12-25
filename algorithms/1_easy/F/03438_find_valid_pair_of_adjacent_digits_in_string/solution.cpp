class Solution {
public:
    string findValidPair(string s) {
        array<int, 10> freqs{};
        const size_t len{s.size()};

        for (const char& ch : s) {
            freqs[static_cast<size_t>(ch - '0')] += 1;
        }

        for (size_t i{0}; i < len - 1; ++i) {
            if (
                s[i] != s[i + 1] &&
                s[i] - '0' == freqs[static_cast<size_t>(s[i] - '0')] &&
                s[i + 1] - '0' == freqs[static_cast<size_t>(s[i + 1] - '0')]
            ) {
                return s.substr(i, 2);
            }
        }

        return "";
    }
};
