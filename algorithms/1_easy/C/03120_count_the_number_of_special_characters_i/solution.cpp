class Solution {
public:
    static int numberOfSpecialChars(const string& word) {
        const size_t len = word.size();
        uint8_t flags[26] = { 0 };

        for (size_t i = 0; i < len; i += 1) {
            if (word[i] >= 'a' && word[i] <= 'z') {
                flags[static_cast<size_t>(word[i] - 'a')] |= 1;
            } else {
                flags[static_cast<size_t>(word[i] - 'A')] |= 2;
            }
        }

        int count = 0;

        for (size_t i = 0; i < 26; i += 1) {
            if (flags[i] == 3) {
                count += 1;
            }
        }

        return count;
    }
};
