class Solution {
public:
    int mySqrt(int x) {
        int64_t high = x;
        int64_t low = 0;

        while (low <= high) {
            const int64_t mid = low + (high - low) / 2;

            if (mid * mid <= x) {
                low = mid + 1;
            } else {
                high = mid - 1;
            }
        }

        return static_cast<int>(high);
    }
};
