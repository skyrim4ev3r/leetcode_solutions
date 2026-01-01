class Solution {
public:
    int numberOfSpecialChars(string word) {
        array<bool, 26> seen_upper {};
        array<bool, 26> seen_lower {};
        array<bool, 26> cant_be_count {};
        int count {0};

        for (const char& ch : word) {
            if (ch >= 'A' && ch <= 'Z') {
                seen_upper[static_cast<size_t>(ch - 'A')] = true;
            } else {
                const size_t index {static_cast<size_t>(ch - 'a')};

                seen_lower[index] = true;
                if (seen_upper[index]) {
                    cant_be_count[index] = true;
                }
            }
        }

        for (size_t i {0}; i < 26; ++i) {
            if (seen_lower[i] && seen_upper[i] && cant_be_count[i] == false) {
                count += 1;
            }
        }

        return count;
    }
};
