class Solution {
public:
    static int maxSatisfied(const vector<int>& customers, const vector<int>& grumpy, int minutes) {
        const size_t len {customers.size()};
        int base {0};

        for (size_t i {0}; i < len; ++i) {
            if (grumpy[i] == 0) {
                base += customers[i];
            }
        }

        const size_t windows_len {static_cast<size_t>(minutes)};
        int curr {0};

        for (size_t i {0}; i < windows_len; ++i) {
            if (grumpy[i] == 1) {
                curr += customers[i];
            }
        }

        int max {curr};

        for (size_t i {windows_len}; i < len ; ++i) {
            if (grumpy[i] == 1) {
                curr += customers[i];
            }

            if (grumpy[i - windows_len] == 1) {
                curr -= customers[i - windows_len];
            }

            max = std::max(max, curr);
        }

        return base + max;
    }
};
