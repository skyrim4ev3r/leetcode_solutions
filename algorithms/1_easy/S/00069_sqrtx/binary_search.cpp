class Solution {
public:
    int mySqrt(int x) {

        long x_i64{static_cast<long>(x)};
        long high{x_i64};
        long low{1};

        while (low <= high) {

            long mid{low + (high - low) / 2};
            long square_mid{mid * mid};

            if (square_mid == x_i64) {
                return static_cast<int>(mid);
            }

            if (square_mid < x_i64) {
                low = mid + 1;
            } else {
                high = mid - 1;
            }
        }

        return static_cast<int>(low) - 1;
    }
};
