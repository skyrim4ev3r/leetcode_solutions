class Solution {
public:
    int arrangeCoins(int n) {

        long x{static_cast<long>(n) * 2};
        long y{static_cast<long>(sqrt(x))};

        if (y * (y + 1) > x) {
            y--;
        }

        return static_cast<int>(y);
    }
};
