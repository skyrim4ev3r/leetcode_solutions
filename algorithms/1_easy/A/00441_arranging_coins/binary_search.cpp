class Solution {
public:
    int arrangeCoins(int n) {

        long n_i64{static_cast<long>(n)};
        long low{1};
        long high{n_i64};

        while (low <= high) {

            long mid{low + (high - low) / 2};
            long curr_sum{(mid * (mid + 1)) / 2};

            if (curr_sum == n_i64) {
                return static_cast<int>(mid);
            }

            if (curr_sum < n_i64) {
                low = mid + 1;
            } else {
                high = mid - 1;
            }
        }

        return static_cast<int>(low) - 1;
    }
};
