constexpr ptrdiff_t freqs_len = 26;

class Solution {
public:
    static bool isAnagram(const string& s, const string& t) {
        if (s.size() != t.size()) {
            return false;
        }

        const ptrdiff_t len = std::ssize(s);
        int freqs[freqs_len] = { 0 };     

        for (ptrdiff_t i = 0; i < len; i += 1) {
            assert(s[i] >= 'a' && s[i] <= 'z' && t[i] >= 'a' && t[i] <= 'z');
            freqs[s[i] - 'a'] += 1;
            freqs[t[i] - 'a'] -= 1;
        }

        for (ptrdiff_t i = 0; i < freqs_len; i += 1) {
            if (freqs[i] != 0) {
                return false;
            }
        }

        return true;
    }
};
