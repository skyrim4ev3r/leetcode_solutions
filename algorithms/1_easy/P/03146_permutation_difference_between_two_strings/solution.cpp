class Solution {
public:
    int findPermutationDifference(string s, string t) {
        const size_t len{s.size()};
        array<int, 26> position_diff{};

        for (size_t i{0}; i < len; ++i) {
            position_diff[static_cast<size_t>(s[i] - 'a')] -= static_cast<int>(i);
            position_diff[static_cast<size_t>(t[i] - 'a')] += static_cast<int>(i);
        }

        int sum{0};
        for (const int &p: position_diff) {
            sum += abs(p);
        }

        return sum;
    }
};
