class Solution {
public:
    bool isSubstringPresent(string s) {
        array<array<bool, 26>, 26> seen {};
        const size_t len {s.size()};

        for (size_t s_index {1}; s_index < len; ++s_index) {
            const size_t i {static_cast<size_t>(s[s_index - 1] - 'a')};
            const size_t j {static_cast<size_t>(s[s_index] - 'a')};

            seen[i][j] = true;

            if (seen[j][i]) {
                return true;
            }
        }

        return false;
    }
};
