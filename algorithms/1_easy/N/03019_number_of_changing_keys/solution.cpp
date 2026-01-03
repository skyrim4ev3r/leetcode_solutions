class Solution {
public:
    int countKeyChanges(string s) {
        int count {0};
        const size_t len {s.size()};

        for (size_t i {1}; i < len; ++i) {
            if (tolower(s[i]) != tolower(s[i - 1])) {
                count += 1;
            }
        }

        return count;
    }
};
