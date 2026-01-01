class Solution {
public:
    static int numberOfSpecialChars(const string& word) {
        array<bool, 26> seen_upper {};
        array<bool, 26> seen_lower {};
        int count {0};

        for (const char& ch : word) {
            if (ch >= 'A' && ch <= 'Z') {
                seen_upper[static_cast<size_t>(ch - 'A')] = true;
            } else {
                seen_lower[static_cast<size_t>(ch - 'a')] = true;
            }
        }

        for (size_t i {0}; i < 26; ++i) {
            if (seen_lower[i] && seen_upper[i]) {
                count += 1;
            }
        }

        return count;
    }
};
