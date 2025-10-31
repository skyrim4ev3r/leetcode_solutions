class Solution {
public:
    char findTheDifference(string s, string t) {
        int freqs[26]{};

        for (const char &ch: s) {
            freqs[static_cast<size_t>(ch - 'a')] += 1;
        }

        for (const char &ch: t) {
            freqs[static_cast<size_t>(ch - 'a')] -= 1;
        }

        for (size_t i{0}; i < 26; ++i) {
            if (freqs[i] != 0) {
                return static_cast<char>(i) + 'a';
            }
        }

        return '0';
    }
};
