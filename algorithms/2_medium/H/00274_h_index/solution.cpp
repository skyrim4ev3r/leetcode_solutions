class Solution {
public:
    int hIndex(vector<int>& citations) {
        ranges::sort(citations, std::greater<>());

        const size_t len{ citations.size() };
        int res{ 0 };

        for (size_t i{ 0 }; i < len; ++i) {
            const int count{ static_cast<int>(i) + 1 };

            if (citations[i] >= count) {
                res = count;
            } else {
                break;
            }
        }

        return res;
    }
};
