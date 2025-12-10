class Solution {
public:
    int countPermutations(vector<int>& complexity) {
        const size_t len{complexity.size()};
        const long long MOD_TO{1'000'000'007};

        for (size_t i{1}; i < len; ++i) {
            if (complexity[i] <= complexity[0]) {
                return 0;
            }
        }

        long long count{1LL};
        long long len_i64{static_cast<long long>(len)};

        for (long long i{2}; i < len_i64; ++i) {
            count = (count * i) % MOD_TO;
        }

        return static_cast<int>(count);
    }
};
