class Solution {
public:
    bool checkAlmostEquivalent(string word1, string word2) {
        array<int, 26> freqs{};

        for (const char &ch: word1) {
            freqs[static_cast<size_t>(ch - 'a')] += 1;
        }

        for (const char &ch: word2) {
            freqs[static_cast<size_t>(ch - 'a')] -= 1;
        }

        for (const int &freq: freqs) {
            if (abs(freq) > 3) {
                return false;
            }
        }

        return true;
    }
};
