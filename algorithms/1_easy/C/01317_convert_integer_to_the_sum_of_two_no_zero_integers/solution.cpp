class Solution {
    inline bool has_any_zero(int n) {
        while (n > 0) {
            if (n % 10 == 0) {
                return true;
            }

            n /= 10;
        }

        return false;
    }
public:
    vector<int> getNoZeroIntegers(int n) {
        for (int i{1}; i < n; ++i) {
            if (!has_any_zero(i) && !has_any_zero(n - i)) {
                return vector<int>{i, n - i};
            }
        }

        return vector<int>{};
    }
};
