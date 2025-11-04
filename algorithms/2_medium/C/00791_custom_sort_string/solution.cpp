/*
	O(m + n)	nested loop wont add complexity
*/

class Solution {
public:
    string customSortString(string order, string s) {
        const size_t freqs_len{26};
        array<int, freqs_len> freqs;
        string res;
        res.reserve(s.size());

        for (const char &ch: s) {
            freqs[static_cast<size_t>(ch - 'a')] += 1;
        }

        for (const char &ch: order) {
            const size_t freq_index{static_cast<size_t>(ch - 'a')};
            int freq{freqs[freq_index]};
            freqs[freq_index] = 0;

            for (int counter{0}; counter < freq; ++counter) {
                res.push_back(ch);
            }
        }

        for (size_t i{0}; i < freqs_len; ++i) {
            if (freqs[i] > 0) {
                char ch = i + 'a';

                for (int counter{0}; counter < freqs[i]; ++counter) {
                    res.push_back(ch);
                }
            }
        }

        return res;
    }
};
