class Solution {
public:
    long long countCompleteDayPairs(vector<int>& hours) {
        array<long long, 24> freqs {};
        long long count {0};

        for (const int& h : hours) {
            freqs[static_cast<size_t>(h % 24)] += 1;
        }

        count += freqs[0] * (freqs[0] - 1) / 2;
        count += freqs[12] * (freqs[12] - 1) / 2;

        for (size_t i{1}; i <= 11; ++i) {
            count += freqs[i] * freqs[24 - i];
        }

        return count;
    }
};
