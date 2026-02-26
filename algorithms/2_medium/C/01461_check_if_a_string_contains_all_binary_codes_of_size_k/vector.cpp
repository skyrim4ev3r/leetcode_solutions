class Solution {
public:
    static bool hasAllCodes(const string& s, const int k) {
        const size_t k_usize{ static_cast<size_t>(k) };
        const size_t flags_len{ static_cast<size_t>(std::pow(2, k)) };
        const size_t s_len{ s.size() };
        if (s_len < flags_len + k_usize - 1) {
            return false;
        }
        vector<bool> seen(flags_len, false);
        const size_t mask{ static_cast<size_t>(std::pow(2, k) - 1) };
        size_t curr_index{ 0 };

        for (size_t i{ 0 }; i < k_usize - 1; ++i) {
            curr_index = (curr_index << 1) | static_cast<size_t>(s[i] - '0');
        }

        for (size_t i{ k_usize - 1 }; i <s_len; ++i) {
            curr_index = mask & ((curr_index << 1) | static_cast<size_t>(s[i] - '0'));
            seen[curr_index] = true;
        }

        return std::all_of(seen.begin(), seen.end(), [](const auto& flag) { return flag; });
    }
};
