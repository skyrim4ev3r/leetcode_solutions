typedef ptrdiff_t isize;

class Solution {
public:
    static int maximumSum(const vector<int>& arr) noexcept {
        assert(std::ssize(arr) > 0);
        const isize len = std::ssize(arr);
        int keep = arr[0];
        int del = 0;
        int res = arr[0];

        for (isize i = 1; i < len; i += 1) {
            const int a = arr[i];
            const int new_keep = std::max(a, keep + a);
            const int new_del = std::max(keep, del +  a);
            del = new_del;
            keep = new_keep;
            res = std::max(res, std::max(del, new_keep));
        }

        return res;
    }
};
