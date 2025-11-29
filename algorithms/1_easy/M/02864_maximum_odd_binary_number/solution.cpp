class Solution {
public:
    string maximumOddBinaryNumber(string s) {
        int ones = count(s.begin(), s.end(), '1');

        *s.rbegin() = '1';
        ones -= 1;

        for (auto it{s.begin()}; it != s.end() - 1; ++it) {
            if (ones > 0) {
                *it = '1';
                ones -= 1;
            } else {
                *it = '0';
            }
        }

        return s;
    }
};
