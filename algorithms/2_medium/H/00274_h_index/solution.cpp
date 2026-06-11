class Solution {
public:
    int hIndex(vector<int>& citations) {
        const ptrdiff_t len = std::ssize(citations);
        assert(len > 0);
        ranges::sort(citations, std::greater<>());
        int res = 0;

        for (ptrdiff_t i = 0; i < len; ++i) {
            const int count = static_cast<int>(i) + 1;

            if (citations[i] >= count) {
                res = count;
            } else {
                break;
            }
        }

        return res;
    }
};
