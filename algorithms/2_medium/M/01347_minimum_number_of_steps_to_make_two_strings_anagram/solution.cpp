class Solution {
public:
    int minSteps(string s, string t) {
        array<int, 26> freqs{};
        for (const char &ch: s) {
            freqs[static_cast<size_t>(ch - 'a')] += 1;
        }
        for (const char &ch: t) {
            freqs[static_cast<size_t>(ch - 'a')] -= 1;
        }
        
        // Chars those are in s but not in t will have positive values
        // Chars those are in t but not in s will have negative values
        // Sum of all values will be 0
        // answer is:
        //          sum(abs(freqs)) / 2
        //     or   sum(positive_freqs)
        //     or   abs(sum(negative_freqs))
        //
        // sum(positive_freqs) is more efficent though not noticeable
        int sum = 0;
        for (size_t i{0}; i < 26; ++i) {
            if (freqs[i] > 0) {
                sum += freqs[i];
            }
        }
        
        return sum;
    }
};
