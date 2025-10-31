class Solution {
public:
    bool isAnagram(string s, string t) {

        if (s.size() != t.size()) {
            return false;
        }

        const size_t freqs_len = 26;
        int freqs[freqs_len]{};

        for (const char &ch: s) {
            freqs[static_cast<size_t>(ch - 'a')] += 1;
        }

        for (const char &ch: t) {
            size_t freqs_index = static_cast<size_t>(ch - 'a');
            freqs[freqs_index] -= 1;

            if (freqs[freqs_index] < 0) {
                return false;
            }
        }

        return true;
    }
};
