class Solution {
public:
    int numPairsDivisibleBy60(vector<int>& time) {
        array<int, 60> freqs{};
        int res{ 0 };

        for (const auto& t : time) {
            const int curr{ t % 60 };
            const int other{ (60 - curr) % 60 };
            const auto freq_other{ freqs[static_cast<size_t>(other)]};

            res += freq_other;
            freqs[static_cast<size_t>(curr)] += 1;
        }

        return res;
    }
};
