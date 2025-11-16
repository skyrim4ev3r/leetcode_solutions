class Solution {
public:
    int countSegments(string s) {
        int segments{0};
        const size_t len{s.size()};

        for (size_t i{0}; i < len; ++i) {
            if (s[i] != ' ' && (i == 0 || s[i - 1] == ' ')) {
                segments += 1;
            }
        }

        return segments;
    }
};
