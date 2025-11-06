class Solution {
public:
    int maxFreqSum(string s) {
        const size_t ALPHABET_LEN{26};
        array<int, ALPHABET_LEN> freqs{};
        for (const char &ch: s) {
            freqs[static_cast<size_t>(ch - 'a')] += 1;
        }

        int max_freqs_vowels{0};
        int max_freqs_consts{0};

        for (size_t i{0}; i < ALPHABET_LEN; ++i) {
            if (i == 0 || i == 4 || i == 8 || i == 14 || i == 20){// 'a', 'e', 'i', 'o', 'u'
                max_freqs_vowels = std::max(max_freqs_vowels, freqs[i]);
            } else {
                max_freqs_consts = std::max(max_freqs_consts, freqs[i]);
            }
        }

        return max_freqs_vowels + max_freqs_consts;
    }
};
