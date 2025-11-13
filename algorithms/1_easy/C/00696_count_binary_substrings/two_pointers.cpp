class Solution {
public:
    int countBinarySubstrings(string s) {
        const size_t len{s.size()};
        int count{0};

        for (size_t i{0}; i < len; ++i) {
            size_t left{i};
            size_t right{i + 1};

            if (s[left] != s[right]) {
                while (left < len && right < len) {
                    count += 1;

                    if (left > 0 && s[left - 1] == s[left] && right < len - 1 && s[right] == s[right + 1]) {
                        left -= 1;
                        right += 1;
                    } else {
                        break;
                    }
                }
            }
        }

        return count;
    }
};
