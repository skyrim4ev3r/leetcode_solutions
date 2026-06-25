constexpr int freqs_len = 10;

class Solution {
public:
    int digitFrequencyScore(int n) {
        int freqs[freqs_len] = { 0 };

        while (n > 0) {
            freqs[n % 10] += 1;
            n /= 10;
        }

        int score = 0;

        for (int i = 1; i < freqs_len; i += 1) {
            score += i * freqs[i];
        }

        return score;
    }
};
