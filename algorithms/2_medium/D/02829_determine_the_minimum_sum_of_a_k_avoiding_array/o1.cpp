class Solution {
public:
    int minimumSum(int n, int k) {
        const int half {k / 2};
        const int cnt_l {std::min(n, half)}; // number of nums to select where num < k
        const int cnt_r {std::max(0, n - half)}; // number of nums to select where num >= k

        const int sum_l {(cnt_l * (cnt_l + 1)) / 2};
        const int sum_r {cnt_r * (k - 1) + (cnt_r * (cnt_r + 1)) / 2};

        return  sum_l + sum_r;
    }
};
