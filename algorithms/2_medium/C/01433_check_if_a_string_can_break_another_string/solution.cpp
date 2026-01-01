class Solution {
    static inline bool check_break(const array<int, 26>& freqs1, const array<int, 26> freqs2) {
        int sum1 {0};
        int sum2 {0};

        for (size_t i {25}; i < 26; --i) {
            sum1 += freqs1[i];
            sum2 += freqs2[i];

            if (sum2 < sum1) {
                return false;
            }
        }

        return true;
    }
public:
    static bool checkIfCanBreak(string s1, string s2) {
        array<int, 26> freqs_s1 {};
        array<int, 26> freqs_s2 {};

        for (const char& ch : s1) {
            freqs_s1[static_cast<size_t>(ch - 'a')] += 1;
        }

        for (const char& ch : s2) {
            freqs_s2[static_cast<size_t>(ch - 'a')] += 1;
        }

        return check_break(freqs_s1, freqs_s2) || check_break(freqs_s2, freqs_s1);
    }
};
