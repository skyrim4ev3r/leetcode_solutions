class Solution {
public:
    int countKConstraintSubstrings(string s, int k) {
        const size_t len {s.size()};
        size_t left {0};
        size_t count {0};
        int zeros {0};
        int ones {0};

        for (size_t right {0}; right < len; ++right) {
            if (s[right] == '0') {
                zeros += 1;
            } else {
                ones += 1;
            }

            while (ones > k && zeros > k) {
                if (s[left] == '0') {
                    zeros -= 1;
                } else {
                    ones -= 1;
                }

                left += 1;
            }

            count += right - left + 1;
        }

        return static_cast<int>(count);
    }
};
