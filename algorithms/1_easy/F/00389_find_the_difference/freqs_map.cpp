constexpr ptrdiff_t freqs_len = 26;

class Solution {
public:
    char findTheDifference(const string& s, const string& t) {
        int freqs[freqs_len] = { 0 };

        for (const char ch : s) {
            assert(ch >= 'a' && ch <= 'z');
            freqs[ch - 'a'] += 1;
        }

        for (const char ch : t) {
            assert(ch >= 'a' && ch <= 'z');
            freqs[ch - 'a'] -= 1;
        }

        for (ptrdiff_t i = 0; i < freqs_len; ++i) {
            if (freqs[i] != 0) {
                return static_cast<char>(i + 'a');
            }
        }

        cout << "invalid input";
        abort();
    }
};
