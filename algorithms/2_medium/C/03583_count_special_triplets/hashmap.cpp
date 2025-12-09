class Solution {
public:
    static int specialTriplets(vector<int>& nums) {
        const long long MOD_TO{1'000'000'007LL};
        unordered_map<int, pair<int, int>> freqs{};
        long long count{0LL};

        for (const int& num : nums) {
            freqs[num].second += 1;
        }

        for (const int& num : nums) {
            auto& pair_num = freqs[num];
            pair_num.second -= 1;

            const auto& pair_num_x2 = freqs.find(num + num);
            if (pair_num_x2 != freqs.end()) {
                count = (count + static_cast<long long>(pair_num_x2->second.first) * static_cast<long long>(pair_num_x2->second.second)) % MOD_TO;
            }

            pair_num.first += 1;
        }

        return static_cast<int>(count);
    }
};
