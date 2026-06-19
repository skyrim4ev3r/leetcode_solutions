typedef ptrdiff_t isize;

class Solution {
public:
    static int wiggleMaxLength(const vector<int>& nums_ref) {
        const isize len = std::ssize(nums_ref);
        if (len <= 1) { return static_cast<int>(len); }
        int cnt = 1;
        int dir = 0;
        auto nums_slice = std::span<const int>(nums_ref.data(), nums_ref.size());

        for (isize i = 1; i < len; i += 1) {
            if (nums_slice[i] > nums_slice[i - 1] && dir != 1) {
                dir = 1;
                cnt += 1;
            }

            if (nums_slice[i] < nums_slice[i - 1] && dir != -1) {
                dir = -1;
                cnt += 1;
            }
        }

        return cnt;
    }
};
