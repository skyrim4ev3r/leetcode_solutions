class Solution {
public:
    long long minimumSteps(string s) {
        const size_t len {s.size()};
        size_t zeros_count {0};
        long long cost {0};

        for (size_t i {0}; i < len; ++i) {
            if (s[i] == '0') {
                cost += static_cast<long long>(i - zeros_count);
                zeros_count += 1;
            }
        }

        return cost;
    }
};
