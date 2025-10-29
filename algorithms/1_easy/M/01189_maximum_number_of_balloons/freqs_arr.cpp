class Solution {
public:
    int maxNumberOfBalloons(string text) {

        int freqs[26]{};

        for (const char &ch: text) {
            freqs[ch - 'a'] += 1;
        }

        return min({freqs['b' - 'a'], freqs['a' - 'a'], freqs['l' - 'a'] / 2, freqs['o' - 'a'] / 2, freqs['n' - 'a']});
    }
};
