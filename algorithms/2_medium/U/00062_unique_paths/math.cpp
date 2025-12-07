class Solution {
public:
    int uniquePaths(int m, int n) {
        long long max = m > n ? m - 1 : n - 1;
        long long min = m > n ? n - 1 : m - 1;
        long long high{max + min};
        long long sum{1};

        for (long long k{max + 1}; k <= high; ++k) {
            sum *= k;

            while (min > 1 && sum % min == 0) {
                sum /= min;
                min -= 1;
            }
        }

        return static_cast<int>(sum);
    }
};
