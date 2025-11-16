class Solution {
public:
    int longestPalindrome(string s) {
        array<int, 26> freqs_upper;
        array<int, 26> freqs_lower;

        for (const char& ch : s) {
            if (ch >= 'a' && ch <='z') {
                freqs_lower[static_cast<size_t>(ch -'a')] += 1;
            } else {
                freqs_upper[static_cast<size_t>(ch -'A')] += 1;
            }
        }

        int count{0};
        bool any_odd{false};

        for (const int& freq : freqs_lower) {
            if ((freq & 1) == 1) {
                count += freq - 1;
                any_odd = true;
            } else {
                count += freq;
            }
        }

        for (const int& freq : freqs_upper) {
            if ((freq & 1) == 1) {
                count += freq - 1;
                any_odd = true;
            } else {
                count += freq;
            }
        }

        if (any_odd) {
            count += 1;
        }

        return count;
    }
};
