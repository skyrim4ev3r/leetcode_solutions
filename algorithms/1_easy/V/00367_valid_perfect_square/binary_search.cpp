class Solution {
public:
    bool isPerfectSquare(int num) {

        long num_i64{static_cast<long>(num)};
        long high{num};
        long low{1};

        while (low <= high) {

            long mid{low + (high - low) / 2};
            long square_mid{mid * mid};

            if (square_mid == num_i64) {
                return true;
            }

            if (square_mid < num_i64) {
                low = mid + 1;
            } else {
                high = mid - 1;
            }
        }

        return false;
    }
};
