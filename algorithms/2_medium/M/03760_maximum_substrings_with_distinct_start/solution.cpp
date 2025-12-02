class Solution {
public:
    int maxDistinct(string s) {
        array<bool, 26> is_seen{};

        for (const char& ch : s) {
            is_seen[static_cast<size_t>(ch - 'a')] = true;
        }

        return std::count(is_seen.begin(), is_seen.end(), true);
    }
};
