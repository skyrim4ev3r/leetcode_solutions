const size_t MIN_WIDTH{ 3 };

class Solution {
    struct pair_hash {
        size_t operator() (const pair<long long, int>& pair) const {
            auto hash1{ std::hash<long long>{}(pair.first) };
            auto hash2{ std::hash<int>{}(pair.second) };
            return hash1 ^ (hash2 << 1);
        }
    };
public:
    static long long countStableSubarrays(const vector<int>& capacity) {
        const size_t len{ capacity.size() };
        long long count{ 0 };
        long long pref_sum_left{ 0 };
        long long pref_sum_right{ 0 };
        unordered_map<pair<long long, int>, int, pair_hash> freqs;

        for (size_t i{ 0 }; i < len; ++i) {
            if (i >= (MIN_WIDTH - 1)) {
                const int val_left{ capacity[i - (MIN_WIDTH - 1)] };
                pref_sum_left += static_cast<long long>(val_left);
                freqs[{pref_sum_left, val_left}] += 1;
            }

            const int val_right{ capacity[i] };
            pref_sum_right += static_cast<long long>(val_right);
            const long long other_sum{ pref_sum_right - (2 * static_cast<long long>(val_right)) };
            const auto& it{ freqs.find({other_sum, val_right}) };
            if (it != freqs.end()) {
                count += static_cast<long long>(it->second);
            }
        }

        return count;
    }
};
