class Solution {
public:
    static int specialTriplets(vector<int>& nums) {
        const long long MOD_TO{1'000'000'007LL};
        const int NUM_MAX{100'000};

        array<pair<int, int>, static_cast<size_t>(NUM_MAX + 1)> freqs{};
        long long count{0LL};

        for (const int& num : nums) {
            freqs[static_cast<size_t>(num)].second += 1;
        }

        for (const int& num : nums) {
            auto& pair_num = freqs[static_cast<size_t>(num)];
            pair_num.second -= 1;

            int num_x2{num + num};
            if (num_x2 <= NUM_MAX) {
                const auto& pair_num_x2 = freqs[static_cast<size_t>(num_x2)];
                count = (count + static_cast<long long>(pair_num_x2.first) * static_cast<long long>(pair_num_x2.second)) % MOD_TO;
            }

            pair_num.first += 1;
        }

        return static_cast<int>(count);
    }
};
