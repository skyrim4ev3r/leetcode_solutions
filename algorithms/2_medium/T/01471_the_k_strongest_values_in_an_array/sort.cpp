typedef ptrdiff_t isize;

class Solution {
public:
    static vector<int> getStrongest(vector<int>& arr, int k) {
        assert(k >= 1 && k <= std::ssize(arr));
        const isize arr_len = std::ssize(arr);
        ranges::sort(arr);
        const isize mid = (arr_len - 1) / 2;
        const int m = arr[mid];
        auto res = vector<int>();
        res.reserve(k);

        isize lo = 0;
        isize hi = arr_len - 1;

        for (int step = 0; step < k; step += 1) {
            if (abs(arr[lo] - m) > abs(arr[hi] - m)) {
                res.push_back(arr[lo]);
                lo += 1;
            } else {
                res.push_back(arr[hi]);
                hi -= 1;
            }
        }

        return res;
    }
};
