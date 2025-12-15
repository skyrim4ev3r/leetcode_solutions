class Solution {
public:
    long long getDescentPeriods(vector<int>& prices) {
        const size_t len{prices.size()};
        long long count{0};
        size_t i{0};

        while (i < len) {
            long long continues{1};

            while (i + 1 < len && prices[i] - 1 == prices[i + 1]) {
                i += 1;
                continues += 1;
            }

            count += continues * (continues + 1) / 2;
            i += 1;
        }

        return count;
    }
};
