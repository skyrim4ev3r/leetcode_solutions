class Solution {
    static inline vector<int> create_diff_vec(const vector<int>& technique1, const vector<int>& technique2) {
        const size_t len{ technique1.size() };
        vector<int> diff(len, 0);

        for (size_t i{ 0 }; i < len; ++i) {
            diff[i] = technique1[i] - technique2[i];
        }

        return diff;
    }
public:
    static long long maxPoints(const vector<int>& technique1, const vector<int>& technique2, int k) {
        const size_t len{ technique1.size() };
        const long long sum_tech2{ std::reduce(technique2.cbegin(), technique2.cend(), 0LL) };
        vector<int> diff{ create_diff_vec(technique1, technique2) };
        ranges::sort(diff, std::greater<>());
        const long long forced_to_pick{ std::reduce(diff.cbegin(), diff.cbegin() + static_cast<size_t>(k), 0LL) };
        long long pick_if_good{ 0 };

        for (size_t i{ static_cast<size_t>(k) }; i < len; ++i) {
            if (diff[i] > 0) {
                pick_if_good += static_cast<long long>(diff[i]);
            }
        }

        return sum_tech2 + forced_to_pick + pick_if_good;
    }
};
