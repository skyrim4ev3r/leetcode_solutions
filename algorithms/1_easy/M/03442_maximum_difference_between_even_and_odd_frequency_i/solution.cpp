class Solution {
public:
    int maxDifference(string s) {
        int min_even {numeric_limits<int>::max()};
        int max_odd {numeric_limits<int>::min()};
        array<int, 26> freqs {};

        for (const char& ch : s) {
            freqs[static_cast<size_t>(ch - 'a')] += 1;
        }

        for (const int& freq : freqs) {
            if (freq > 0) {
                if((freq & 1) == 1) {
                    max_odd = std::max(max_odd, freq);
                } else {
                    min_even = std::min(min_even, freq);
                }
            }
        }

        return max_odd - min_even;
    }
};
