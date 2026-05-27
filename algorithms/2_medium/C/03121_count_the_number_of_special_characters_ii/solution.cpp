class Solution {
public:
    static int numberOfSpecialChars(const string& word) {
        uint32_t lower = 0;
        uint32_t upper = 0;
        uint32_t lower_after_upper = 0;

        for (const unsigned char ch : word) {
            if (ch >= 'a' && ch <= 'z') {
                const uint32_t bit = 1u << (ch - 'a');
                lower |= bit;

                if ((upper & bit) != 0) {
                    lower_after_upper |= bit;
                }
            } else if (ch >= 'A' && ch <= 'Z') {
                const uint32_t bit = 1u << (ch - 'A');
                upper |= bit;
            }
        }

        return __builtin_popcount(lower & upper & (~lower_after_upper));
    }
};